#include <stdio.h>

int main(void)
{
   int gs1, identifier, publisher, item, check;

   printf("Enter ISBN: ");
   scanf("%d -%d -%d -%d -%d", &gs1, &identifier, &publisher, &item, &check);

   printf("GS1 prefix: %d\n", gs1);
   printf("Group identifier: %d\n", identifier);
   printf("Publisher code: %d\n", publisher);
   printf("Item number: %d\n", item);
   printf("Check digit: %d\n", check);

   return 0;
}
