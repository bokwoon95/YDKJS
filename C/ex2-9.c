#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
	int ans;

	ans = bitcount((unsigned)7);
	printf("ans = %d\n", ans);
	return 0;
}

int bitcount(unsigned x) {
	int b = 0;
	while (x) {
		x &= (x - 1);
		b++;
	}
	return b;
}
