#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int element_compare(const void *ip1, const void *ip2)
{
    int result;
    int *ipi1 = (int *)ip1, /* Cast parameters to pointers to int */
        *ipi2 = (int *)ip2;

    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;

    return result;
}

int main(void)
{
    int i;
    double *pmalloc = malloc(sizeof(double) * 100);
    srand(time(NULL));
    for (i = 0; i < 100; i++)
    {
        pmalloc[i] = rand();
    }
    qsort(pmalloc, 100, sizeof(double), element_compare);

    for (i = 0; i < 100; i++)
    {
        printf("%f\n", pmalloc[i]);
    }

    free(pmalloc);

    printf("%f\n", pmalloc[1]);

    return 0;
}
