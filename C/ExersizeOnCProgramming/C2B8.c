#include <stdio.h>

int main(void)
{
	float amount, interest, payment, rate, a, b, c;
	printf("Enter amount of loan: ");
	scanf("%f", &amount);
	printf("Enter interest rate: ");
	scanf("%f", &interest);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	
	rate = ( interest / 100 ) / 12.0f;

	a = ( amount - payment ) * ( 1.0f + rate );
	b = ( a - payment ) * ( 1.0f + rate );
	c = ( b - payment ) * ( 1.0f + rate );
	
	printf("Balance remaining after first payment: $%.2f\n\
Balance remaining after second payment: $%.2f\n\
Balance remaining after third payment: $%.2f\n", a, b, c);

	return 0;
}
