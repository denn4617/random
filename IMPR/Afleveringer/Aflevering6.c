#include <stdio.h>
#include <math.h>

#define PI 3.14159

double gx(double x);
double hx(double x);
double trap(double a, double b, int n, double (*f)(double));

int main(void)
{
    int n = 0;
    
    printf("Function h(x) approximation (a = -2.00000 , b = 2.00000):\n");
    for (n = 2; n <= 128; n *= 2)
    {
        printf("n = %5d:    %f\n", n, trap(-2, 2, n, hx));
    }

    printf("\n");
    
    printf("Function g(x) approximation (a = 0.00000 , b = %0.5f):\n", PI);
    for (n = 2; n <= 128; n *= 2)
    {
        printf("n = %5d:    %f\n", n, trap(0, PI, n, gx));
    }
    
    return 0;
}

double trap(double a, double b, int n, double f(double))
{
    double i = 0.0, area = 0.0, sum = 0, h = (b - a) / n;

    for (i = a + h; i <= b - h; i += h)
    {
        sum += f(i);
    }

    area = ((h / 2) * (f(a) + f(b) + 2 * sum));

    return area;
}

double gx(double x)
{
    double function_g = pow(x, 2) * sin(x);
    
    return function_g;
}
double hx(double x)
{
    double function_h = sqrt(4 - pow(x, 2));
    
    return function_h;
}