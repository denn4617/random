#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double answer_i, answer_d;

    answer_i = sqrt(pow((4-1)+(0-0)+(4-3)+(1-1)+(2-4)+(4-2)+(3-4)+(3-2)+(0-2), 2.0));
    answer_d = sqrt(pow((4-4)+(0-0)+(4-4)+(1-1)+(2-2)+(4-4)+(3-3)+(3-3)+(0-4), 2.0));

    printf("\nDistance mellem software og interaktion: %f\n", answer_i);
    printf("Distance mellem software og datalogi: %f\n", answer_d);
    return 0;
}
