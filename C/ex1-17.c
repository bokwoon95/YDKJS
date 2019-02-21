#include <stdio.h>

int main(void)
{
	int i;
	int cc = 0;
	char ch;
	char line[1000];

	while ((ch = getchar()) != EOF || ch != ';') {
		line[cc++] = ch;
		if (ch == '\n') {
			for (i = 0; i < cc; ++i) {
				putchar(line[i]);
			}
			cc = 0;
		}
	}
	putchar('\n');

	return 0;
}
