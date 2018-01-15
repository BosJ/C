#include <stdio.h>

void init_io (void);
void print_outputs (void);
void print_inputs (void);

typedef struct outputs {
  int val;
  char nr;
} output;

typedef struct inputs {
  int val;
  char nr;
} input;

struct ios {
   #define DEF_OUT(name) output name;
   #define DEF_IN(name) input name;
   #include "io.def"
   int notused;
} io;

void init_io (void) {
  int i = 1, j = 1;
  #define DEF_OUT(name) \
    io.name.nr = i; io.name.val = 0; i++;
  #define DEF_IN(name)  \
    io.name.nr = j; io.name.val = 1; j++;
  #include "io.def"
}

void print_outputs (void) {
  #define DEF_OUT(name) \
    printf("output%d: %d\n", io.name.nr, io.name.val);
  #include "io.def"
}

void print_inputs (void) {
  #define DEF_IN(name) \
    printf("input%d: %d\n", io.name.nr, io.name.val);
  #include "io.def"
}

int main() {
  init_io();
  print_outputs();
  print_inputs();
}
