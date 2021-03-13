#include <stdio.h>

int main(void)
{
	int v;
	
	printf("Enter velocity: ");
	scanf("%d", &v);
	
	if (0 <= v && v < 1) printf("Calm\n");
	else if (v < 3) printf("Light air\n");
	else if (v < 27) printf("Breeze\n");
	else if (v < 47) printf("Gale\n");
	else if (v < 63) printf("Storm\n");
	else printf("Hurricane\n");
	
	return 0;
}
