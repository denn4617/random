/*    
 *     | Navn: Dennis Kilic                                                          |
 *     | Gruppenummer: A317b                                                         |
 *     | Studieretning: Software                                                     |
 *     | Email: dkilia19@student.aau.dk                                              |
 *     | Hjælp: Casper Benjamin Norspang hjalp med pointers(cnorsp19@student.auu.dk) |
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Erklæring af prototyper*/
void regnemaskine(void);
void skan_data(char *pOperator, double *pOperand);
void naeste_operation(char operator, double operand, double *pAkkumulator);
int tjek_operator(char operator);

int main(void)
{
    /*Udprinting af de forskellige operatorer og deres funktioner*/
    printf("De gyldige binære operatorer:\n");
    printf("+     addition af akkumulatoren med operanden\n");
    printf("-     subtraktion af akkumulatoren med operanden\n");
    printf("*     multiplikation af akkumulatoren med operanden\n");
    printf("/     division af akkumulatoren med operanden\n");
    printf("^     potensopløftning af akkumulatoren med operanden\n");

    printf("\nDe gyldige unære operatorer:\n");
    printf("#    for kvadratroden af akkumulatoren\n");
    printf("%%    for at vende fortegnet af akkumulatoren\n");
    printf("!    for at dividere 1 med akkumulatoren\n");
    printf("q    for at afslutte regnemaskinen med slutresultatet\n\n");

    regnemaskine();

    return 0;
}

/*Funktion der kører hele regnemaskinen*/
void regnemaskine(void)
{
    double operand, akkumulator = 0;
    char operator;

    /*While løkke, der tjekker hvorvidt om operatoren er forskellig fra 'q', for at determinere om programmet henholdsvis skal afslutte eller køre videre*/
    while (operator!= 'q')
    {
        skan_data(&operator, &operand);
        naeste_operation(operator, operand, &akkumulator);

        /*Denne if-else kæde bestemmer hvad der skal printes ud fra om operatoren er lig med eller forskellig fra 'q'*/
        if (operator== 'q')
        {
            printf("Endegyldige resultat: %f\n", akkumulator);
        }
        else if (operator!= 'q')
        {
            printf("Nuværende resultat: %f\n", akkumulator);
        }
        else
        {
            printf("En fejl er blevet lavet");
        }
    }
}

/*Denne funktion får inputtet fra brugeren, som så bruges i regnemaskinen*/
void skan_data(char *pOperator, double *pOperand)
{
    printf("Indtast en af de ovennævnte operatorer, og en mulig operand: ");
    scanf(" %c", &*pOperator);

    if (tjek_operator(*pOperator) == 1)
    {
        scanf(" %lf", &*pOperand);
    }
    else
    {
        *pOperand = 0.0;
    }
}

/*Denne funktion udfører selve udregningerne ved hjælp af switches for henholdsvis de binære og unære operatorer*/
void naeste_operation(char operator, double operand, double *pAkkumulator)
{
    if (tjek_operator(operator) == 1)
    {
        switch (operator)
        {
        case '+':
            *pAkkumulator = *pAkkumulator + operand;
            break;

        case '-':
            *pAkkumulator = *pAkkumulator - operand;
            break;

        case '*':
            *pAkkumulator = *pAkkumulator * operand;
            break;

        case '^':
            *pAkkumulator = pow(*pAkkumulator, operand);
            break;

        case '/':
            if (operand != 0)
            {
                *pAkkumulator = *pAkkumulator / operand;
            }
            break;

        default:
            break;
        }
    }
    else if (tjek_operator(operator) == 0)
    {
        switch (operator)
        {
        case '%':
            *pAkkumulator = -(*pAkkumulator);
            break;

        case '!':
            *pAkkumulator = 1 / *pAkkumulator;
            break;

        case '#':
            if (*pAkkumulator >= 0.0)
            {
                *pAkkumulator = sqrt(*pAkkumulator);
            }
            break;
        case 'q':
            break;

        default:
            break;
        }
    }
}

/*Denne funktion bruges til at tjekkke hvilken operator der er at gøre med. Hvis det er en binær operator returneres der 1 ellers returneres der 0*/
int tjek_operator(char operator)
{
    if (operator== '+' || operator== '-' || operator== '*' || operator== '^' || operator== '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
