#include <stdio.h>

#define TAX 0.05f

int main(void)
{
	float a, b;
	printf("Please enter the amount of the money: ");
	scanf("%f", &a);
	b = a * ( 1 + TAX );
	printf("With tax added: %.2f\n", b);
	return 0;
}
