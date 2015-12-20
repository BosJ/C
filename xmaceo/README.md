#xmacro example

Lets say we have something as shown below and we want to do something to all members of ```io``` of type ```output``` and something else to all members of type ```input``` in a _scalable_ way. Because it is not possible to evaluate a type at runtime this is not trivial;
```c
typedef struct outputs {
  int val;
  char nr;
} output;

typedef struct inputs {
  int val;
  char nr;
} input;

struct ios {
  output out1;
  output out2;
  input in1;
  input in2;
  input in3;
  int notused;
} io;
```
macro.c shows a preprocessor-metaprogramming solution using a technique called XMACROS. During debugging 
```gcc -E xmacro.c -o xmacro.i``` can be used to apply the preprocessor and inspect the results.
