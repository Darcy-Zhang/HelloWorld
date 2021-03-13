#include <stdio.h>

int main(void)
{
   float t;
   int number;
   scanf("%f%d", &t, &number);
   printf("%.3f\n%d\n", t / number, number * 2);
   return 0;
}