#include <stdio.h>

int main(void)
{
	int digit, a;
	
	printf("Enter a number: ");
	scanf("%d", &digit);
	
	if (0 <= digit && digit <= 9) a = 1;
	else if (10 <= digit && digit <= 99) a = 2;
	else if (100 <= digit && digit <= 999) a = 3;
	else if (1000 <= digit && digit <= 9999) a = 4;
	
	printf("The number %d has %d digits\n", digit, a);
	
	return 0;
}
