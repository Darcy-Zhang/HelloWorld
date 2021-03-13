#include <stdio.h>

int main(void)
{
	int h, m, total, i= 0, a[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
	
	printf("Enter a 24-hour time: ");
	A:scanf("%d :%d", &h, &m);
	
	if (h < 0 || h >= 24 || m < 0 || m >= 60)
		{
			printf("Incorrect format, please enter again: ");
			goto A;
		} 
	
	total = h * 60 + m;
	
	for (; i < 8, a[i] < total; i++)
	/* empty loop body */;
	
	if (i < 7)
	(total - a[i]) < (a[i + 1] - total) ? : i++;
	
	printf("Closest departure time is ");
	
	switch (i)
	{
	case 0: printf("8:00 a.m., arriving at 10:16 a.m.\n"); break;
	case 1: printf("9:43 a.m., arriving at 11:52 a.m.\n"); break;
	case 2: printf("11:19 a.m., arriving at 1:31 p.m.\n"); break;
	case 3: printf("12:47 a.m., arriving at 3:00 p.m.\n"); break;
	case 4: printf("2:00 p.m., arriving at 4:08 p.m.\n"); break;
	case 5: printf("3:45 p.m., arriving at 5:55 a.m.\n"); break;
	case 6: printf("7:00 p.m., arriving at 9:20 a.m.\n"); break;
	case 7: printf("9:45 a.m., arriving at 11:58 a.m.\n"); break;
	}
	
	return 0;
}
