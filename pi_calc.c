
/*  Approximation of pi with Leibniz formula using threads
    http://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80

    Compile with -lpthread e.q.
    gcc pi_calc.c -o pi_calc -lpthread 

    Jaco Bos, University of Twente
    Besturings-systemen, assignment 1, task 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

void *piCalculate(void *ptr);
void *piPrint(void *ptr);

pthread_mutex_t mutexPi = PTHREAD_MUTEX_INITIALIZER;

double piVal = 0;
int iteration = 0;
bool print = true;


int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("usage: %s iterations seconds.\n", argv[0]);
        exit(1);
    }

    int var[] = {0,0};
    var[0] = atoi(argv[1]); // max iterations
    var[1] = atoi(argv[2]); // max seconds
    pthread_t calcThread, printThread;

    pthread_mutex_init(&mutexPi, NULL);
      
    if (pthread_create(&calcThread, NULL, &piCalculate, (void*) var) != 0) {
        printf("Could not create calculation.\n");
    }
    if (pthread_create(&printThread, NULL, &piPrint, NULL) != 0) {
        printf("Could not create print.\n");
    }
    
    pthread_join(printThread, NULL);
    pthread_join(calcThread, NULL);
    
    pthread_mutex_destroy(&mutexPi);
    printf("Final result:\n# Iterations: %d, PI: %f\n", iteration, piVal);
    exit(0);
}


void *piCalculate(void *ptr) 
{

    int maxIteration = ((int*) ptr)[0];
    int maxSeconds = ((int*) ptr)[1];
    double num = 1;
    int add = 1;
    
    struct timeval tim;
    gettimeofday(&tim, NULL);
    unsigned long stopTime = 1000000 * tim.tv_sec + tim.tv_usec + (1000000 * maxSeconds);
    unsigned long time_in_micros = 1000000 * tim.tv_sec + tim.tv_usec;

    while (iteration < maxIteration && time_in_micros < stopTime) {
        // Get mutual exclusion on our variables:
        pthread_mutex_lock(&mutexPi);
        iteration++;
        if (add) {
            piVal += 4/num;
            add = 0;
        } else {
            piVal -= 4/num;
            add = 1;
        }
        num+=2;
        // To slow the calculation down just a bit.
        int i;
        for (i = 0; i < 10000; i++) {
        }
        pthread_mutex_unlock(&mutexPi);
        // Update the time:
        gettimeofday(&tim, NULL);
        time_in_micros = 1000000 * tim.tv_sec + tim.tv_usec;
    }

    print = false; 
    printf("Finished calculation\n");
    return NULL;
}


void *piPrint(void *ptr) 
{
    printf("Start print Thread.\n");
    struct timeval tim;
    gettimeofday(&tim, NULL);
    unsigned long stopTime = 1000000 * tim.tv_sec + tim.tv_usec + 1000000;

    while(print) {
        gettimeofday(&tim, NULL);
        unsigned long time_in_micros = 1000000 * tim.tv_sec + tim.tv_usec;
        if (time_in_micros > stopTime) {
            // Obtain the lock on iteration and piVal
            pthread_mutex_lock(&mutexPi);
            printf("Iteration: %d, PI: %f\n", iteration, piVal);
            pthread_mutex_unlock(&mutexPi);
            stopTime = 1000000 * tim.tv_sec + tim.tv_usec + 1000000;
        }
    }

    return NULL;
}
