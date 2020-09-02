/* Opgave 11 (side 125 - IMPR bog) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int m, n;

    printf("Please press enter a value for 'm' and 'n':\n");
    printf("'m' must have a larger value than 'n'\n");

    printf("m: ");
    scanf(" %d", &m);
    
    printf("n: ");
    scanf(" %d", &n);
   
    int side1 = (m * m) - (n * n),
        side2 = 2 * (m * n),
        hypotenuse = (m * m) + (n * n);

    printf("Side 1: %d\nSide 2: %d\nHypotenuse: %d", side1, side2, hypotenuse);

    return 0;
}