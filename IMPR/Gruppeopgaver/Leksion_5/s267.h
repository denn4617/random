#include <stdio.h>
#include <stdlib.h>

int sum_iter(int n){
    int i, sum, entiresum = 0;

    for (i = 0, sum = 0; i < n; i++)
    {
        sum = 1 + sum;
        entiresum = sum + entiresum;
        printf("%d + ", sum);
    }
    printf("\nHele summen er %d\n", entiresum);

    if (entiresum == (((n * (n + 1))) / 2)){
        printf("Lig med\n");
    } 
    else{
        printf("Forskellig fra\n");
    }
    return entiresum;
}