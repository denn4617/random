#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum forret {nachos, tartelleter, lakserrulle, greaskarsuppe};
enum hovderet {steak, burger, lasagne, sushi};
enum dessert {is, cremebruhle, kage, risalamente};

void maaltid(void);
int choosemeal(void);
int valg(void);
void vealgforret(int);
void vealghovderet(int);
void vealgdessert(int);

int main(void)
{

    srand(time(NULL));

    int i;
    for (i = 0; i < 25; i++)
    {
        printf("\n");
        maaltid();
    }

    return 0;
}

void maaltid(void)
{
    int forretvalg = choosemeal();
    int hovderetvalg = choosemeal();
    int dessertvalg = choosemeal();
    vealgforret(forretvalg);
    vealghovderet(hovderetvalg);
    vealgdessert(dessertvalg);
}

int choosemeal(void)
{
    int valg = (rand() % 4);
    return valg;
}

void vealgforret(mealnr)
{
    switch (mealnr)
    {
    case nachos:
        printf("Din forret er nachos\n");
        break;
    
    case tartelleter:
        printf("Din forret er tartelletter\n");
        break;
    
    case lakserrulle: 
        printf("Din forret er lakseruller\n");
        break;

    case greaskarsuppe: 
        printf("Din forret er greaskarsuppe\n");
        break;

    default:
        break;
    }
}

void vealghovderet(mealnr)
{
    switch (mealnr)
    {
    case steak:
        printf("Din hovderet er steak\n");
        break;
    
    case burger:
        printf("Din hovderet er burger\n");
        break;
    
    case lasagne: 
        printf("Din hovderet er lasagne\n");
        break;

    case sushi: 
        printf("Din hovderet er sushi\n");
        break;

    default:
        break;
    }
}

void vealgdessert(mealnr)
{
    switch (mealnr)
    {
    case is:
        printf("Din dessert er is\n");
        break;
    
    case cremebruhle:
        printf("Din dessert er cremebruhle\n");
        break;
    
    case kage: 
        printf("Din dessert er kage\n");
        break;

    case risalamente: 
        printf("Din dessert er risalamente\n");
        break;

    default:
        break;
    }
}