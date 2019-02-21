#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LU_WIDTH (sizeof(unsigned int) * CHAR_BIT)

unsigned setbits(unsigned x, int p, int n, int y);
char *decimal_to_binary(int n);

// NOTE: I can't do this. I don't understand what p & n mean
// No test data was given, so I can't even test their getbits() to see what
// they mean by p & n
int main(void)
{
	char *ans;
	unsigned lu = 0;

	lu = setbits(lu, 4, 3, 3);
	ans = decimal_to_binary(lu);
	printf("ans = %s\n", ans);

	printf("%s\n");
	return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
	unsigned lu;
	lu = ~(unsigned)0 << 5 >> 5;
	return lu;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

char *decimal_to_binary(int n) {
   int c, d, count;
   char *pointer;
   count = 0;
   pointer = (char*)malloc(32+1);
   if (pointer == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; c >= 0 ; c--)
   {
      d = n >> c;
      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
      count++;
   }
   *(pointer+count) = '\0';
   return  pointer;
}
