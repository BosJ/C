#include <stdio.h>

#define CLAMP(v,min,max) ((v>max) ? max : ((v<min) ? min : v))

int main() {

  printf("CLAMP(0,1,3) = %d\n", CLAMP(0,1,3));
  printf("CLAMP(1,1,3) = %d\n", CLAMP(1,1,3));
  printf("CLAMP(2,1,3) = %d\n", CLAMP(2,1,3));
  printf("CLAMP(3,1,3) = %d\n", CLAMP(3,1,3));
  printf("CLAMP(4,1,3) = %d\n", CLAMP(4,1,3));

  return(1);
}
