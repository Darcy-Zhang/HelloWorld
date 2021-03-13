#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int m1, m2, d1, d2, y1, y2;
	bool i;
	
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d /%d /%d", &m1, &d1, &y1);
	
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d /%d /%d", &m2, &d2, &y2);
	
	if (y1 < y2) i = 1;
	else if (y1 > y2) i = 0;
	else if (m1 < m2) i = 1;
	else if (m1 > m2) i = 0;
	else if (d1 < d2) i = 1;
	else if (d1 > d2) i = 0;
	else
	{
		printf("Error!\n");
		goto a;
	}
	switch (i)
	{
		case 0: printf("%d/%d/%d is earlier than %d/%d/%d", m2, d2, y2, m1, d1, y1); break;
		case 1: printf("%d/%d/%d is earlier than %d/%d/%d", m1, d1, y1, m2, d2, y2); break;
	}
	
	a:return 0;
}
