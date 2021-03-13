#include <stdio.h>

int main(void)
{
	int a, b;
	
	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &a, &b);
	
	printf("You entered the number ");
	
	if (a == 1)
	{
		switch (b)
		{
			case 0: printf("ten"); break;
			case 1: printf("eleven"); break;
			case 2: printf("twelve"); break;
			case 3: printf("thirteen"); break;
			case 4: printf("fourteen"); break;
			case 5: printf("fifteen"); break;
			case 6: printf("sixteen"); break;
			case 7: printf("seventeen"); break;
			case 8: printf("eighteen"); break;
			case 9: printf("nineteen"); break;
		}
		
		printf(".\n");
		
		goto exit;
	}
	
	switch (a)
	{
		case 2: printf("twenty"); break;
		case 3: printf("thirty"); break;
		case 4: printf("fourty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;
	}
	
	printf("-");
	
	switch (b)
	{
		case 0: printf("\b"); break;
		case 1: printf("one"); break;
		case 2: printf("two"); break;
		case 3: printf("three"); break;
		case 4: printf("four"); break;
		case 5: printf("five"); break;
		case 6: printf("six"); break;
		case 7: printf("seven"); break;
		case 8: printf("eight"); break;
		case 9: printf("nine"); break;
	}
	
	exit:return 0;
}
