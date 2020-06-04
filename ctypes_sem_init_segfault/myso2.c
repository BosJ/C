#include <stdio.h>
#include "myso.h"

void use_sem_init(void) {
  printf("%d", sem_init());
}
