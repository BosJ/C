#include <stdio.h>

#define print_ptr(x) printf("%s=%p\n", #x, x);

void on();
void off();
void (*func_ptr)() = on;

void on() 
{
    func_ptr = off;
}

void off() 
{
    func_ptr = on;
}

int main() 
{
   while(1) {
    	(*func_ptr)();
        print_ptr(func_ptr);
    	sleep(1);
   }
   return 1;
}
