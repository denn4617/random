#include <stdio.h>

#define EUVAL 0.89
#define DKKVAL 6.66
#define RUVAL 66.43
#define YENVAL 119.9

void dollarCalc(double input, double *peuro, double *pdkk, double *pru, double *pyen);

int main(void)
{
    double euro, dkk, ru, yen, i;
    for (i = 0; i <= 100; i++)
    {
        dollarCalc(i, &euro, &dkk, &ru, &yen);    
        printf("| %5.0f dollars = | %5.2f Euro + | %5.2f Kroner | %5.2f Rubles | %5.2f Yen |\n", i, euro, dkk, ru, yen);
    }
    
    return 0;
}

void dollarCalc(double i, double *peuro, double *pdkk, double *pru, double *pyen){
    *peuro = i * EUVAL;
    *pdkk  = i * DKKVAL;
    *pru   = i * RUVAL;
    *pyen  = i * YENVAL;

}