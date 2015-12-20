#xmacro example

Lets say we have something as shown below and we want to do something to all members of ```io``` of type ```output``` and somthing else to all members of type ```output``` in a __scalable__ way. 
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
