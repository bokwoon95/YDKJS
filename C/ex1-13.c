#include <stdio.h>

int main(void)
{
	char ch;
	int cc = 0;
	int cc_array[20];
	int max = 0;
	int i,j;
	// zero out the array
	for (i = 0; i < 19; ++i) {
		cc_array[i] = 0;
	}
	// accumulate the character counts inside the array
	while ((ch = getchar()) != EOF && ch != ';') {
		if (ch == ' ' || ch <= '\t' || ch == '\n') {
			if (cc <= 20) {
				cc_array[cc - 1] += 1;
				if (cc > max) {
					max = cc;
				}
			}
			cc = 0;
		} else {
			cc += 1;
		}
	}
	// print the array values (for debugging)
	for (i = 0; i < 20; ++i) {
		printf("%d)%d ", i, cc_array[i]);
	}
	printf("\nmax = %d\n", max);
	// print the histogram
	for (i = max; i >= 0; --i) {
		for (j = 0; j < 20; ++j) {
			if (cc_array[j] <= i) {
				printf(" ");
			} else {
				printf("#");
			}
		}
		printf("\n");
	}
	printf("────────────────────\n");
	printf("00000000011111111112\n");
	printf("12345678901234567890\n");
	printf("\n");
	return 0;
}
