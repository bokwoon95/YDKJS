#include <stdio.h>

int main(void)
{
	char ch;
	while ((ch = getchar()) != EOF) {
		if (ch == '\t') {
			putchar('\\');
			putchar('t');
		} else if (ch == 127 || ch == 8) {
			putchar('\\');
			putchar('b');
		} else {
			putchar(ch);
		}
	}
	return 0;
}
