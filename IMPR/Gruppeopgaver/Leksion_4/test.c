#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int smallNr, bigNr, buffer, i, scanres, temp;
    char cont = 'y';
    
    do
    {
        printf("Please enter two positive integers, that you want to find the GCD of: ");
        scanres = scanf("%d%d", &smallNr, &bigNr);

        /* ordering our inputs, so that we can calculate on them later */
        if (smallNr > bigNr)
        {
            temp = smallNr;
            smallNr = bigNr;
            bigNr = temp;
        }

        /*Cheking if two intergers were being input */
        if (scanres != 2)
        {
            printf("I did not detect two intergers being put in\n");
            fflush(stdin);
        }

        /* Checking for negative input */ 
        else if (smallNr <= 0 || bigNr <= 0)
        {
            printf("Two POSITIVE integers....\n");
        }

        /* Doing the actual calculations */
        else
        {
            for (i = 1; i < smallNr; i++)
            {
                if ((smallNr % i == 0) && (bigNr % i == 0))
                {
                    buffer = i;
                }
            }

            printf("The GCD of %d and %d is %d\n", smallNr, bigNr, buffer);
            printf("Want to continue? y/n: ");
            scanf(" %c", &cont);
        }

    } while (cont == 'y' || cont == 'Y');

    return 0;
}