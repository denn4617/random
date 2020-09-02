#include <stdio.h>
#include <stdlib.h>

#define TIMER 3600
#define MINUTTER 60


void hours_minutes_seconds(int input, int *phours, int *pminutes, int *pseconds)
{
    *phours   = input / TIMER;
    *pminutes = (input % TIMER) / MINUTTER;
    *pseconds = ((input % TIMER) % MINUTTER) % MINUTTER;

    if (*phours == 0 || *pminutes == 0 || *pseconds == 0)
    {
        if (*phours == 0 && *pminutes != 0 && *pseconds != 0)
        {
            printf(*pminutes == 1 ? "%d minut og " : "%d minutter og ", *pminutes);
            printf(*pseconds == 1 ? "%d sekundt" : "%d sekunder", *pseconds);
        }
        if (*pminutes == 0 && *phours != 0 && *pseconds != 0)
        {
            printf(*phours == 1 ? "%d time og " : "%d timer og ", *phours);
            printf(*pseconds == 1 ? "%d sekundt" : "%d sekunder",*pseconds);
        }
        if (*pseconds == 0 && *phours != 0 && *pminutes != 0)
        {
            printf(*phours == 1 ? "%d time og " : "%d timer og ", *phours);
            printf(*pminutes == 1 ? "%d minut" : "%d minutter", *pminutes);
        }
        if (*phours == 0 && *pminutes == 0)
        {
            printf(*pseconds == 1 ? "%d sekundt" : "%d sekunder", *pseconds);
        }
        if (*phours == 0 && *pseconds == 0)
        {
            printf(*pminutes == 1 ? "%d minut" : "%d minutter", *pminutes);
        }
        if (*pminutes == 0 && *pseconds == 0)
        {
            printf(*phours == 1 ? "%d time" : "%d timer", *phours);
        } 
    }
    else
    {
        printf(*phours == 1 ? "%d time, " : "%d timer, ", *phours);
        printf(*pminutes == 1 ? "%d minut og " : "%d minutter og ", *pminutes);
        printf(*pseconds == 1 ? "%d sekundt" : "%d sekunder", *pseconds);
    }
}
int main(void)
{
    int input, hours, minutes, seconds;
    printf("Enter the amount of secconds you want to convert: ");
    scanf("%d", &input);

    hours_minutes_seconds(input, &hours, &minutes, &seconds);

    return 0;
}