/* Solution to https://projecteuler.net/problem=1 
 * Find the sum of all the multiples of 3 or 5 below 1000. */

#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, total = 0;

    for(i=0; i<1000; i++) {
        if( !(i % 3) || !(i % 5) ) {
            total += i;
        }
    } 

    printf("%d\n",total);
    
    return 0;
}
