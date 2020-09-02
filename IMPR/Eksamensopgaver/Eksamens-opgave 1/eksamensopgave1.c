#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double binary_operator(char operator, double operand, double current_value)
{

    if (operator == '+')
    {
        current_value = current_value + operand;
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '-')
    {
        current_value = current_value - operand;
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '*')
    {
        current_value = current_value * operand;
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '/')
    {
        current_value = current_value / operand;
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '^')
    {
        current_value = pow(current_value, operand);
        printf("Result so far is %f\n", current_value);
    }
    else
    {
        printf("you dun goofed\n");
    }
    return current_value;
}

double unary_operator(char operator, double operand, double current_value)
{
    if (operator == '#')
    {
        current_value = sqrt(current_value);
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '%')
    {
        current_value = !(current_value);
        printf("Result so far is %f\n", current_value);
    }
    else if (operator == '!')
    {
        current_value = 1 / current_value;
        printf("Result so far is %f\n", current_value);
    }
    
    return current_value;
}

int main(void)
{
    double operand, current_value = 0;
    char operator;

    while (operator != 'q')
    {
        printf("Enter operator, and an optional operand: ");
        scanf("%c %lf", &operator, &operand);

        if (operator== '+' || '-' || '*' || '/' || '^')
        {
            binary_operator(operator, operand, current_value);
        }
        else if (operator== '#' || '%' || '!')
        {
            unary_operator(operator, operand, current_value);
        }
    }

    return 0;
}

/*
double scan_data()
{
    double operand, current_value = 0;
    char operator;
    
    printf("Enter operator, and an optional operand: ");
    scanf("%c %lf", operator, operand);

    if (operator == "+")
    {
        current_value = current_value + operand;
        printf("Result so far is %lf", current_value);
    }
    else if (operator == "-")
    {
        current_value = current_value - operand;
        printf("Result so far is %lf", current_value);
    } 
    else
    {
        printf("you dun goofed");
    }
    
    
    
}

double do_next_operation(double *poperator, double *poperand)
{
}

double run_calculator()
{
}
*/