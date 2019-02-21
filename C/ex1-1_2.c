#include <stdio.h>

int main(void)
{
	printf("hello, ");
	printf("world");
	printf("\n");

	// if supplied an unknown escape character like '\z', it will print out 'z' literally
	printf("\t\n");

	return 0;
}
