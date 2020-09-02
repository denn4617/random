#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6
#define ROUNDS_AMOUNT 15

/* Declaration of function prototypes */
void print_arr(void);
int roll_die(void);

enum upper_section{ones, twos, threes, fours, fives, sixes, onePair, twoPairs, threeOfAKind, fourOfAKind, smallStraight, largeStraight, fullHouse, chance, yatzy};

int main(void)
{  
    print_arr();

    return 0;
}

void print_arr(void)
{
    int i, dice_amount = 0, 
        *arr_dice = malloc(sizeof(int) * dice_amount);

    if (arr_dice == NULL)
    {
        printf("Error: Memory could not be allocated!");
        exit(0);
    }

    srand(time(NULL)); /* Seeding the random number generator.
                         Do this only once! */
    printf("Enter the amount of dice(over 5): ");
    scanf(" %d", &dice_amount);

    if (dice_amount >= 5)
    {

        for (i = 0; i < dice_amount; i++)
        {
        printf("Round %d: ", i);
        arr_dice[i] = roll_die();
        printf("%d\n ", arr_dice[i]);
        }
        
    }
    else
    {
        printf("You didn't insert a number greater than 5!\n");
    }

    free(arr_dice);
}

int roll_die(void)
{
    return (rand() % DIE_MAX_EYES) + 1;
}
/*
int upper_section()
{

}

int lower_section(int dice_amount)
{
    for (int i = 0; i < dice_amount; ++i)
    {
        switch (i):

        case onePair:
            roundresult = onePair();

    }
}

void run_game()
{

}

int onePair()
{

}

*/