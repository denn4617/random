#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.1

int main(void){
    double r, x, y, point_radius;
    /*Input fra brugeren for x, y og r*/
    printf("Announce the value for x: ");
    scanf("%lf", &x);
    printf("Announce the value for y: ");
    scanf(" %lf", &y);
    printf("Annouce your radius: ");
    scanf("%lf", &r);

    /*Udregning af afstanden mellem origo og punktet (phytagoras)*/
    point_radius = sqrt(x * x + y * y);

    /*Udregning af resultatet*/
    printf("Punktet ligger %s", point_radius > r + DELTA ? "uden for cirklen" : point_radius <= r - DELTA ? "inden i cirklen" : "på cirklens periferi");

    return 0;
}