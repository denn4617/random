#include <stdio.h>
#define j (n*(n+1))/2
int main(void){
    int n, sum, i, entiresum = 0;

    printf("Indtast et tal: ");
    scanf("%d", &n);
    
    for (i = 1, sum = 0; i <= n; i++)
    {
        sum = sum + 1;
        entiresum = sum + entiresum;
        printf("%d + ", sum);
        
    }

    printf("\nThe entire sum is %d", entiresum);

    if (j == entiresum){
        printf("\nThe values are the same");
    } else
    {
        printf("\nThe values are different");
    }
    
    
    return 0;
}