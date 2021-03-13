#include <stdio.h>

int main(void)
{
	char letter;
	scanf("%c", &letter);
	printf("%c\n", letter - 'a' + 'A');
	return 0;
}