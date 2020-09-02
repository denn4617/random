#include <stdio.h>
#define START_POP 9870
#define MAX_POP 30000

int main(void){
    int count_years = 0;
    double population;

    for (population=START_POP; population <= MAX_POP; count_years++)
    {
     population = population * 1.1;  
     printf("Population: %lf\n", population); 
    }
    printf("It will take %d years before the population surpasses 30.000", count_years);
    return 0;
}