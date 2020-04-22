#!/bin/bash

usage="$(basename "$0") [-v variable] [-p process] [-w] [-h] 
where:
    -v  variable name (global or static c-variable in process)
    -p  process name (that is running)
    -w  live watch
    -h  show this help text"

watch=0

while getopts ':hv:p:wn' option; do
  case "$option" in
    h) echo "$usage"
       exit
       ;;
    v) variable=$OPTARG
       ;;
    :) printf "missing argument for -%s\n" "$OPTARG" >&2
       echo "$usage" >&2
       exit 1
       ;;
    p) if pgrep -x "$OPTARG" >/dev/null; then
           process=$OPTARG
       else
         echo "$OPTARG not running"
         exit 1
       fi
       ;;
    :) printf "missing argument for -%s\n" "$OPTARG" >&2
       echo "$usage" >&2
       exit 1
       ;;
    w) watch=1
       ;;
   \?) printf "illegal option: -%s\n" "$OPTARG" >&2
       echo "$usage" >&2
       exit 1
       ;;
  esac
done

while [ 1 ]
do
    result="$(gdb -p $(pidof $process) -ex "p $variable" -batch 2>&1)"

    echo $result

    if [ "$watch" -eq 0 ]; then
        exit
    fi

    sleep 1
done
