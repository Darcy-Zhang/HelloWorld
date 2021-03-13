#include <stdio.h>

int main(void)
{
	float i;
	
	printf("Enter your income: ");
	scanf("%f", &i);
	
	if (i <= 750) printf("Your tax is %f", i * 0.01);
	else if (i <= 2250) printf("Your tax is %f", 7.5 + (i - 750) * 0.02);
	else if (i <= 3750) printf("Your tax is %f", 37.5 + (i - 2250) * 0.03);
	else if (i <= 5250) printf("Your tax is %f", 82.5 + (i - 3750) * 0.04);
	else if (i <= 7000) printf("Your tax is %f", 142.5 + (i - 5250) * 0.05);
	else printf("Your tax is %f", 230 + (i - 7000) * 0.06);
	
	return 0;
}
