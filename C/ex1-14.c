#include <stdio.h>

int main(void)
{
	int i,j;
	char ch;
	int atoz[26];
	int max = 0;

	for (i = 0; i < 26; ++i) atoz[i] = 0;

	while ((ch = getchar()) != EOF && ch != ';') {
		if (ch >= 'a' && ch <= 'z') {
			atoz[ch - 'a'] += 1;
		}
	}

	for (i = 0; i < 26; ++i) {
		if (atoz[i] > max) {
			max = atoz[i];
		}
	}

	printf("%d\n", max);
	for (i = max; i >= 0; --i) {
		for (j = 0; j < 26; ++j) {
			if (atoz[j] <= i) {
				printf(" ");
			} else {
				printf("#");
			}
		}
		printf("\n");
	}
	printf("──────────────────────────\n");
	printf("abcdefghijklmnopqrstuvwxyz\n");
	return 0;
}
