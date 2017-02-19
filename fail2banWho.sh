#!/bin/bash

# Show location of fail2ban banned IP's

sed -n -e 's/^.*Ban //p' /var/log/fail2ban.log.1 | while read -r line; do curl ipinfo.io/"$line"; done > result.txt

cat result.txt | grep -A 2 city
