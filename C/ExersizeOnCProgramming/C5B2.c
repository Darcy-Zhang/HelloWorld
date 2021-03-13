#include <stdio.h>

int main(void)
{
	int h, m;
	
	printf("Enter a 24-hour time: ");
	scanf("%d :%d", &h, &m);
	
	if (h == 12 && m == 0)
	{
		printf("Equivalent 12-hour time: 12:00 AM");
		goto a;
	}
	
	if (0 <= h && h <= 11) printf("Equivalent 12-hour time: %d:%d AM", h, m);
	else if (12 <= h && h <= 23) printf("Equivalent 12-hour time: %d:%d PM", h-12, m);
	
	a:return 0;
} 
