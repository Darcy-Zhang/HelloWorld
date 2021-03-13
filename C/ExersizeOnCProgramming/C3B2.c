//对齐的规则是，在\t之前的内容的大小为n，若n不是8的倍数，对其在右侧空格补齐为8的倍数，如果大小正好是8的倍数，则右侧再补8个空格。
#include <stdio.h>

int main(void)
{
   int number, year, month, day;
   float price;

   printf("Enter item number: ");
   scanf("%d", &number);

   printf("Enter unit price: ");
   scanf("%f", &price);

   printf("Enter purchase date  (mm/dd/yyyy) : ");
   scanf("%d /%d /%d", &month, &day, &year);

   printf("Item    \tUnit    \tPurchase\n\
          \tPrice          \tDate\n\
%d          \t$%-6.2f    \t%.2d/%.2d/%.4d\n", number, price, month, day, year);

   return 0;
}
