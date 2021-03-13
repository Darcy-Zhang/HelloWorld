#include <stdio.h>

int main(void)
{
        float x;
        printf("I will calculate ( 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 ) for you.\n");
        printf("Please enter the value of x: ");
        scanf("%f", &x);
        printf("It equals %.3f.\n", (((( 3.0f * x + 2.0f ) * x - 5.0f ) * x - 1.0f ) * x + 7.0f ) * x - 6.0f);
        return 0;
}

