#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int grade;
	bool i = 0;
	for (; i == 0;)
	{
		printf("Enter numerical grade: ");
		scanf("%d", &grade);
		if (grade > 100 || grade < 0)
		{
			printf("Illegal grade, please try again!\n");
			continue;
		} 
		i = 1;
	}
	
	printf("Letter grade: ");
	
	switch (grade / 10)
	{
		case 0: case 1: case 2: case 3: case 4: case 5: printf("F"); break;
		case 6: printf("D"); break;
		case 7: printf("C"); break;
		case 8: printf("B"); break;
		case 9: case 10: printf("A"); break;
	}
	
	return 0;
} 
