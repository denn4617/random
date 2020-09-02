#include <stdio.h>
#include <stdlib.h>
#include "funccollect.h"

int main(void)
{
    int k = 3;
    int inputarr[9] = {0};

    question(inputarr);

    Points inputPoint = {.coordinates = inputarr, .distance = 0};

    Points PointArr[45];

    createPointArr(PointArr, inputarr);
    
    qsort(PointArr, 45, sizeof(Points), cmpFunc);

    inputPoint.identifier = kPicker(PointArr, k, inputPoint);

    printf("Identifier: %s\n", inputPoint.identifier);

    percentageCalc(PointArr, inputPoint);
    
    return 0;
}