#include <stdio.h>

int main(void)
{

    int i, l, m;
    for (i = 0; i <= 10; i++)
    {
        if (i <= 5)
        {
            for (l = 0; l <= i; l++)
            {

                printf("%d ", l);
            }
        }
        else if (i > 5)
        {
            for (m = 0; m <= (10 - i); m++)
            {
                printf("%d ", m);
            }
        }
        printf("\n");
    }
    return 0;
}