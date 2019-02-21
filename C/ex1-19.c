#include <stdio.h>

int main(void)
{
	int i, cc, temp;
	char ch;
	int line[1000];

	i = cc = temp = 0;

	while ((ch = getchar()) != EOF && ch != ';') {
		if (ch == '\n') {
			for (i = 0; i < cc/2; ++i) {
				temp = line[i];
				line[i] = line[cc - 1 - i];
				line[cc - 1 - i] = temp;
			}
			for (i = 0; i < cc; ++i) {
				putchar(line[i]);
			}
			putchar('\n');
			cc = 0;
		} else {
			line[cc++] = ch;
		}
	}
	return 0;
}
