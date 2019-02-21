#include <stdio.h>

int main(void)
{
	char ch;
	int space_f = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			if (!space_f) {
				putchar(' ');
				space_f = 1;
			}
		} else {
			putchar(ch);
			space_f = 0;
		}
	}
	return 0;
}
