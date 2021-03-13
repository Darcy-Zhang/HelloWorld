#include <stdio.h>

int main(void)
{
   int a, b, c, d;
   scanf("%d%d%d%d", &a, &b, &c, &d);
   printf("%d %d\n", (60 * c + d - 60 * a - b) / 60, (60 * c + d - 60 * a - b) % 60);
   return 0;
}