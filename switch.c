#include <stdio.h>

/* var declaration between switch and first case is not Ok */ 
int main() {

	int x = 1;
	
	switch(x) {
	
	char greeting[] = "Hello\n";
	
	case 1:
		printf("%s", greeting);
		break;
	default:
		break;
	}
}
