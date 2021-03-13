#include <stdio.h>

int main(void)
{
   float x = 333.485f;

   printf("%6d,%4d\n", 86, 1040);
   printf("%12.5e\n", 30.253);
   printf("%.4f\n", 83.162);
   printf("%-6.2g\n", .0000009979);

   printf("%-8.1e, %10.6e, %-8.3f, %6.0f", x, x, x, x);
   return 0;
}
