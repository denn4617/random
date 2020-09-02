/*    
 *     | Navn: Dennis Kilic                                                                           |
 *     | Gruppenummer: A317b                                                                          |
 *     | Studieretning: Software                                                                      |
 *     | Email: dkilia19@student.aau.dk                                                               |
 *     | Hjælp: Casper Benjamin Norspang hjalp med min "full_house" funktion(cnorsp19@student.auu.dk) |
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

/*Prototype declaration*/
void run_game(int diceAmount);
int* dice_array(int diceAmount);
int comparator(const void *p, const void *q);
int comparator_full_house(const void *p, const void *q);
int roll_die(void);
void print_dice(int *diceArray, int diceAmount);
int upper_section(int diceAmount, int roundDice, int *scoreboardArray, int resultUpper);
int lower_section(int diceAmount, int diceRound, int *scoreboardArray, int resultLower);
int one_pair(int diceAmount, int *diceArray);
int two_pairs(int diceAmount, int *diceArray);
int three_of_a_kind(int diceAmount, int *diceArray);
int four_of_a_kind(int diceAmount, int *diceArray);
int small_straight(int diceAmount, int *diceArray);
int large_straight(int diceAmount, int *diceArray);
int full_house(int diceAmount, int *diceArray);
int chance_function(int diceAmount, int *diceArray);
int yatzy_function(int diceAmount, int *diceArray);
void scoreboardPrint(int resultTotal, int bonus, int scoreboardArray[]);

enum roundDice{ones = 1, twos, threes, fours, fives, sixes, onePair, twoPairs, threeOfAKind, fourOfAKind, smallStraight, largeStraight, fullHouse, chance, yatzy};

int main(void)
{
    char answer = 'y';
    int diceAmount = 0;

    srand(time(NULL));
    /*While loop that checks if the user wants to play again, based on the char (answer)*/
    while (answer != 'n' && answer != 'N')
    {
        printf("Enter the amount of dice(5 or greater): ");
        scanf(" %d", &diceAmount);
        /*Checks if the user has inserted a number lower than 5*/
        while (diceAmount < 5)
        {
            printf("The dice amount is not greater than or equal to 5! Try again: ");
            scanf(" %d", &diceAmount);
        }
        
        run_game(diceAmount);
        printf("Do you want to keep playing? (y/n):");
        scanf(" %c", &answer);
    }

    return 0;
}
/*This is the function that makes the game run by looking at the upper_section and lower_section*/
void run_game(int diceAmount)
{
    int i, resultLower = 0, resultUpper = 0, resultTotal = 0, bonus = 0,
    *scoreboardArray = (int*)malloc(sizeof(int) * 15);


    for (i = ones; i <= yatzy; i++)
    {
        if (i < onePair)
        {
            resultUpper = upper_section(diceAmount, i, scoreboardArray, resultUpper);
        }
        
        if ((i == sixes) && (resultUpper > 62))
        {
            printf("\nSince your score is %d, you will be awarded 50 bonus points!\n", resultUpper);
            bonus = 50;
        }

        if (i > sixes)
        {
            resultLower = lower_section(diceAmount, i, scoreboardArray, resultLower);
        }
    }

    resultTotal = resultUpper + bonus + resultLower;  
    /*The results and bonus will be putted into a scoreboard*/
    scoreboardPrint(resultTotal, bonus, scoreboardArray);
}
/*This function is used together with the qsort function, to sort the array from highest to lowest*/
int comparator(const void *p, const void *q)
{
    int l = *(const int *)p; 
    int r = *(const int *)q;

    return (r-l);
}
/*This function is used together with the qsort function, to sort the array from lowest to highest*/
int comparator_full_house(const void *p, const void *q)
{
    int l = *(const int *)p; 
    int r = *(const int *)q;

    return (l-r);
}
/*This function takes and randomizes numbers between 1 and 6*/
int roll_die(void)
{
    return (rand() % DIE_MAX_EYES) + 1;
}
/*This function prints the dice, that are in use for the current round*/
void print_dice(int *diceArray, int diceAmount)
{
    int i;

    printf("[");

    for (i = 0; i < diceAmount; i++)
    {
        if (i == diceAmount - 1)
        {
            printf("%d", diceArray[i]);
        }else
        {
            printf("%d, ", diceArray[i]);
        }
    }
    printf("]\n");
}
/*This function only works on the the rounds "ones" to "sixes"*/
int upper_section(int diceAmount, int roundDice, int *scoreboardArray, int resultUpper)
{
    int i, resultRound = 0, diceInRound = 0, 
    *diceArray = (int*)malloc(sizeof(int) * diceAmount);

    if (diceArray == NULL)
    {
        printf("Error: Memory could not be allocated!");
        exit(0);
    }
    /*This is where the values are put into the dice array byy using the roll_die function*/
    for (i = 0; i < diceAmount; i++)
    {
        diceArray[i] = roll_die();
    }
    

    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == roundDice)
        {
            if (diceInRound < 5)
            {
                ++diceInRound;
                resultRound = resultRound + roundDice;
            }
        }
    }
    resultUpper += resultRound;

    printf("\nDice: ");
    print_dice(diceArray, diceAmount);
    printf("We're looking for %d's, with the final result of: %d", roundDice, resultRound);

    free(diceArray);

    scoreboardArray[roundDice] = resultRound;

    return resultUpper;
}

/*This function consist of a switch, which looks at all the functions from the lower section, and returns a resultLower value*/
int lower_section(int diceAmount, int diceRound, int *scoreboardArray, int resultLower)
{
    int i, resultRound, *diceArray = (int*)malloc(sizeof(int) * diceAmount); 

    if (diceArray == NULL)
    {
        printf("Error: Memory could not be allocated!");
        exit(0);
    }
    
    for (i = 0; i < diceAmount; i++)
    {
        diceArray[i] = roll_die();
    }
    
    qsort(diceArray, diceAmount, sizeof(int), comparator);


    switch (diceRound)
    {
    case onePair:
        resultRound = one_pair(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for One Pair, with the final result of: %d \n", resultRound);
        break;

    case twoPairs:
        resultRound = two_pairs(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Two Pairs, with the final result of: %d \n", resultRound);
        break;

    case threeOfAKind:
        resultRound = three_of_a_kind(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Three Of A Kind, with the final result of: %d \n", resultRound);
        break;

    case fourOfAKind:
        resultRound = four_of_a_kind(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Four Of A Kind, with the final result of: %d \n", resultRound);
        break;

    case smallStraight:
        resultRound = small_straight(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Small Straight, with the final result of: %d \n", resultRound);
        break;

    case largeStraight:
        resultRound = large_straight(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Large Straight, with the final result of: %d \n", resultRound);
        break;

    case fullHouse:
        resultRound = full_house(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Full House, with the final result of: %d \n", resultRound);
        break;

    case chance:
        resultRound = chance_function(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Chance, with the final result of: %d \n", resultRound);
        break;

    case yatzy:
        resultRound = yatzy_function(diceAmount, diceArray);
        resultLower += resultRound;
        printf("\nDice: ");
        print_dice(diceArray, diceAmount);
        printf("We're looking for Yatzy, with the final result of: %d \n", resultRound);
        break;
    }
    scoreboardArray[diceRound] = resultRound;

    free(diceArray);

    return resultLower;
}

int one_pair(int diceAmount, int *diceArray)
{
    int i, result = 0;
    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == diceArray[i + 1] && result == 0)
        {
            result = diceArray[i] + diceArray[i + 1];
        }
    }

    return result;
}

int two_pairs(int diceAmount, int *diceArray)
{
    int i, numberOfPairs = 0, result = 0, firstVal;
    
    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == diceArray[i + 1] && numberOfPairs < 2 && firstVal != diceArray[i])
        {
            result += diceArray[i] + diceArray[i +1];
            numberOfPairs++;
            i++;
            firstVal = diceArray[i];
        }
    }

    if (numberOfPairs == 2)
    {
        return result;
    }
    return 0;
}

int three_of_a_kind(int diceAmount, int *diceArray)
{
    int i, result = 0;

    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == diceArray[i + 2] && result == 0)
        {
            result = diceArray[i] + diceArray[i + 1] + diceArray[i + 2];
        }
    }
    return result;
}

int four_of_a_kind(int diceAmount, int *diceArray)
{
    int i, result = 0;
    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == diceArray[i + 3] && result == 0)
        {
            result = diceArray[i] + diceArray[i + 1] + diceArray[i + 2] + diceArray[i + 3];
        }
    }
    return result;
}

int small_straight(int diceAmount, int *diceArray)
{
    int i, foundOne = 0, foundTwo = 0, foundThree = 0, foundFour = 0, foundFive = 0, result = 0;

    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == 1)
        {
            foundOne = 1;
        }
        if (diceArray[i] == 2)
        {
            foundTwo = 1;
        }
        if (diceArray[i] == 3)
        {
            foundThree = 1;
        }
        if (diceArray[i] == 4)
        {
            foundFour = 1;
        }
        if (diceArray[i] == 5)
        {
            foundFive = 1;
        }
    }

    if (foundOne == 1 && foundTwo == 1 && foundThree == 1 && foundFour == 1 && foundFive == 1)
    {
        result = 15;
    }
    return result;
}

int large_straight(int diceAmount, int *diceArray)
{
    int i, foundTwo = 0, foundThree = 0, foundFour = 0, foundFive = 0, foundSix = 0, result = 0;

    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == 2)
        {
            foundTwo = 1;
        }
        if (diceArray[i] == 3)
        {
            foundThree = 1;
        }
        if (diceArray[i] == 4)
        {
            foundFour = 1;
        }
        if (diceArray[i] == 5)
        {
            foundFive = 1;
        }
        if (diceArray[i] == 6)
        {
            foundSix = 1;
        }
    }

    if (foundTwo == 1 && foundThree == 1 && foundFour == 1 && foundFive == 1 && foundSix == 1)
    {
        result = 20;
    }
    return result;
}

int full_house(int diceAmount, int *diceArray)
{
    int i, threeKindScore = 0, threeKindValue = 0, pairScore = 0, pairValue = 0, result = 0;

    qsort(diceArray, diceAmount, sizeof(int), comparator_full_house);

    for (i = diceAmount - 1; i >= 0; --i)
    {
        if (diceArray[i] == diceArray[i - 2] && i != 1 && threeKindScore == 0 && diceArray[i] != pairValue)
        {
            threeKindScore += diceArray[i] + diceArray[i - 1] + diceArray[i - 2];
            threeKindValue = diceArray[i];
            --i, --i;
        } else if (diceArray[i] == diceArray[i - 1] && pairScore == 0 && diceArray[i] != threeKindValue)
        {
            pairScore += diceArray[i] + diceArray[i - 1];
            pairValue = diceArray[i];
        }    
    }

    if (threeKindValue > 0 && pairScore > 0)
    {
        result = threeKindScore + pairScore;
    }
    
    return result;
}

int chance_function(int diceAmount, int *diceArray)
{
    int result = 0;

    result = (diceArray[0] + diceArray[1] + diceArray[2] + diceArray[3] + diceArray[4]);

    return result;
}

int yatzy_function(int diceAmount, int *diceArray)
{
    int i, result = 0;
    for (i = 0; i < diceAmount; i++)
    {
        if (diceArray[i] == diceArray[i + 4] && result == 0)
        {
            result = diceArray[i] + diceArray[i + 1] + diceArray[i + 2] + diceArray[i + 3] + diceArray[i + 4];
        }
    }
    return result;
}

/*Scoreboard function for visuals*/
void scoreboardPrint(int resultTotal, int bonus, int *scoreboardArray)
{
    printf("\n ____________________________");
    printf("\n|           YATZY            |");
    printf("\n| Ones                :%5.1d |", scoreboardArray[ones]);
    printf("\n| Twos                :%5.1d |", scoreboardArray[twos]);
    printf("\n| Threes              :%5.1d |", scoreboardArray[threes]);
    printf("\n| Fours               :%5.1d |", scoreboardArray[fours]);
    printf("\n| Fives               :%5.1d |", scoreboardArray[fives]);
    printf("\n| Sixes               :%5.1d |", scoreboardArray[sixes]);
    printf("\n| Bonus               :%5.1d |", bonus);
    printf("\n|                            |");
    printf("\n| One pair            :%5.1d |", scoreboardArray[onePair]);
    printf("\n| Two pair            :%5.1d |", scoreboardArray[twoPairs]);
    printf("\n| Three of a kind     :%5.1d |", scoreboardArray[threeOfAKind]);
    printf("\n| Four of a kind      :%5.1d |", scoreboardArray[fourOfAKind]);
    printf("\n| Small Straight      :%5.1d |", scoreboardArray[smallStraight]);
    printf("\n| Large Straight      :%5.1d |", scoreboardArray[largeStraight]);
    printf("\n| Full house          :%5.1d |", scoreboardArray[fullHouse]);
    printf("\n| Chance              :%5.1d |", scoreboardArray[chance]);
    printf("\n| Yatzy               :%5.1d |", scoreboardArray[yatzy]);
    printf("\n|____________________________|");
    printf("\n| Total               :%5.1d |", (resultTotal + bonus));
    printf("\n|____________________________|");
    printf("\n\n");
}