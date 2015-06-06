#include <stdio.h>

void led_on();
void led_off();
void (*statefunc)() = led_on;

static int led = 0;

void led_on() {
	printf("led: %d\n", led = 1);
	statefunc = led_off;
}

void led_off() {
  	printf("led: %d\n", led = 0);
	statefunc = led_on;
}

int main() {
  	while(1) {
    	(*statefunc)();
    	sleep(1); 
  	}
  	return 1;
}
