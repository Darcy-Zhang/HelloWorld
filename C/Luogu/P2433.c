#include <stdio.h>
#include <string.h>
#define pi 3.141593f

int main(void)
{
   printf("I love Luogu!\n");
   printf("6 4\n");
   printf("%d\n%d\n%d\n", 14 / 4, 14 - (14 % 4), 14 % 4);
   printf("%6f", (float)500 / 3);
   printf("%d\n", 480 / 32);
   printf("10.816653\n");
   printf("%d\n%d\n%d\n", 110, 90, 0);
   printf("%f\n%f\n%f\n", 2 * pi * 5, pi * 25, 4 / 3 * pi * 125);
   return 0;
}