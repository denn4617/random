/*    
 *  Denne del virker. Kan printe randomized terninger for en runde
 */
    int i, dice_amount = 0;

    srand(time(NULL)); /* Seeding the random number generator.
                         Do this only once! */
    printf("Enter the amount of dice(over 5): ");
    scanf(" %d", &dice_amount);

    int dice[dice_amount];

    if (dice_amount >= 5)
    {
        printf("Array:");
        for (i = 1; i <= dice_amount; i++)
        {
            dice[i] = roll_die();
            /* printf("Die %d shows: %d\n", i, dice[i]);*/
            printf(" %d", dice[i]);
        }
        printf("\n");
    }
    else
    {
        printf("You didn't insert a number greater than 5!\n");
    }

/*
 *  - Brug for loop til at indlæse værdierne i et array, og lav en switch i for-loopet
 *  - Lav to switches, hvor den ene er for hvilken runde vi er i, og den anden laver beregninger for alle reglerne (Ones -> Yatzy)
 */
