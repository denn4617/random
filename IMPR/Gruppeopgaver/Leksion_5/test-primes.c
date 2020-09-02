#include <stdio.h>
#include "primes.h"
#include <time.h>
int main(void){
    
    int i, result, number_of_prime = 0;
    double time_spent = 0.0;

    clock_t begin = clock();
    for (i = 1; number_of_prime < 2000000; i++)
    {
        result = is_prime(i);

        if (result){
            ++number_of_prime;
            printf("\nprime %d: %d", number_of_prime, i);
        }
        
    }
clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nTime elapsed is %f seconds", time_spent);

    return 0;
}