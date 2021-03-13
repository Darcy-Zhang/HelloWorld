#include <stdio.h>

int main(void)
{
	int a, b, c, d, e;
	printf("Enter a dollar amount: ");
	scanf("%d", &a);
	b = a / 20;
	c = ( a - b * 20 ) / 10;
	d = ( a - b * 20 - c * 10 ) / 5;
	e = a - b * 20 - c * 10 - d * 5;
	printf("$20 bills: %d\n\
$10 bills: %d\n\
$5 bills: %d\n\
$1 bills: %d\n", b, c, d, e);
	return 0;
}
