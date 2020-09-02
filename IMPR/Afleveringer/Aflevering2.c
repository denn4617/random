#include <stdio.h>

#define MINUTTER 60
#define TIMER    3600

int main(void){
    int input_sek;

    printf("Indtast antal sekunder: ");
    scanf("%d", &input_sek);

    int timer    = input_sek / TIMER,
        minutter = (input_sek % TIMER) / MINUTTER,
        sekunder = ((input_sek % TIMER) % MINUTTER) % MINUTTER;

    if (timer == 0 || minutter == 0 || sekunder == 0)
    {
        if (timer == 0 && minutter != 0 && sekunder != 0)
        {
            printf(minutter == 1 ? "%d minut og " : "%d minutter og ", minutter);
            printf(sekunder == 1 ? "%d sekundt" : "%d sekunder", sekunder);
        }
        if (minutter == 0 && timer != 0 && sekunder != 0)
        {
            printf(timer == 1 ? "%d time og " : "%d timer og ", timer);
            printf(sekunder == 1 ? "%d sekundt" : "%d sekunder",sekunder);
        }
        if (sekunder == 0 && timer != 0 && minutter != 0)
        {
            printf(timer == 1 ? "%d time og " : "%d timer og ", timer);
            printf(minutter == 1 ? "%d minut" : "%d minutter", minutter);
        }
        if (timer == 0 && minutter == 0)
        {
            printf(sekunder == 1 ? "%d sekundt" : "%d sekunder", sekunder);
        }
        if (timer == 0 && sekunder == 0)
        {
            printf(minutter == 1 ? "%d minut" : "%d minutter", minutter);
        }
        if (minutter == 0 && sekunder == 0)
        {
            printf(timer == 1 ? "%d time" : "%d timer", timer);
        } 
    }
    else
    {
        printf(timer == 1 ? "%d time, " : "%d timer, ", timer);
        printf(minutter == 1 ? "%d minut og " : "%d minutter og ", minutter);
        printf(sekunder == 1 ? "%d sekundt" : "%d sekunder", sekunder);
    }
    
    return 0;
}