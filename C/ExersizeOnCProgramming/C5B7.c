#include <stdio.h>

int main(void)
{
	int a[4], M = 0, m = 0, i = 1;
	
	printf("Enter four integers: ");
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	
	for (i = 1; i < 4; i++)
	{
		if (a[M] < a[i]) M = i;
		if (a[m] > a[i]) m = i;
	}
	
	printf("Largest: %d\n\
Smallest: %d\n", a[M], a[m]);
	return 0;
}
