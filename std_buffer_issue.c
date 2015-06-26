
/* The stream stdout is line-buffered when it points to a terminal,
 * partial lines will not appear until fflush or exit is called, 
 * or a newline is printed. On the other hand, stderr is always 
 * unbuffered. Therefore, in this example hello-out will not appear.
 * */

#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1) {
        fprintf(stdout,"hello-out");
        fprintf(stderr,"hello-err");
        sleep(1);
    }
    return 1;
}
