/* Exercise for section 2.3 (side 88 - IMPR borg) */
#include <stdio.h>

int main(void){
    int m;
    int n;

    printf("Enter two integers> ");

    scanf("%d%d", &m, &n);
    m = m + 5;
    n = 3 + n;

    printf("m = %d\nn = %d\n", m, n);
    return 0;
}