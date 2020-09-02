#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Calculation of discriminant */
double find_discriminant(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;
    return discriminant;
}
/* Calculation of finding 1 root if discriminant == 0 */
double find_root_one(double a, double b, double discriminant)
{
    double root1;

    if (discriminant == 0)
    {
        root1 = -b / (2 * a);
    }

    else if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
    }

    return root1;
}
/* Calculation of finding 2 roots if drisciminant > 0 */
double find_root_two(double a, double b, double discriminant)
{
    double root2;

    root2 = (-b - sqrt(discriminant)) / (2 * a);

    return root2;
}
/* Calculation of the quadratic equation */
void solveQuadraticEquation(double a, double b, double c)
{
    double root1, root2, discriminant;
    discriminant = find_discriminant(a, b, c);

    if (discriminant > 0)
    {
        root1 = find_root_one(a, b, discriminant);
        root2 = find_root_two(a, b, discriminant);
        printf("\n2 roots was found: %f and %f", root1, root2);
    }
    else if (discriminant == 0)
    {
        root1 = find_root_one(a, b, discriminant);
        printf("\n1 root was found: %f", root1);
    }
    else if (discriminant < 0)
    {
        printf("\nNo root was found");
    }
}
/* Prints roots of the quadratic equation (a*x*x+b*x+c=0) */
int main(void)
{
    double a = 1, b = 1, c = 1;
    do
    {
        printf("\nPlease enter three doubles for a, b and c in the quadratic equation(a b c): \n");
        scanf("%lf %lf %lf", &a, &b, &c);
        if ((a || b || c) && a != 0)
        {
            solveQuadraticEquation(a, b, c);
        }
        else
        {
            printf("False input\n");
        }

    } while (a || b || c);

    return 0;
}