/* Solution to https://projecteuler.net/problem=2 
 * By considering the terms in the Fibonacci sequence 
 * whose values do not exceed four million, find the sum 
 * of the even-valued terms.
 * Jaco Bos bos.jch@gmail.com */

#include <stdio.h>
#include <unistd.h>

int main()
{
    long i, fib = 1, total = 0;

    for(i=1; i<4000000; i+=fib) {
        fib += i;
        if ( !(i % 2) ) {
            total += i; 
        }
        if ( !(fib % 2) ) {
            total += fib; 
        }
    } 

    printf("%ld\n",total);
    
    return 0;
}
