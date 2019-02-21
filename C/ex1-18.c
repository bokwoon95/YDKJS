#include <stdio.h>

int main(void)
{
	int i;
	int cc;
	int blanks, tabs, trailing_blanks, trailing_tabs;
	char ch, line[1000];

	cc = 0;
	blanks = tabs = 0;
	trailing_blanks = trailing_tabs = 0;

	while ((ch = getchar()) != EOF && ch != ';') {
		line[cc++] = ch;
		if (ch == '\n') {
			for (i = cc - 1; i >= 0; --i) {
				if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
					cc -= 1;
				} else {
					break;
				}
			}
			for (i = 0; i < cc; ++i) {
				putchar(line[i]);
			}
			putchar('\n');
			printf("cc is %d\n", cc);
			cc = 0;
		}
	}
	return 0;
}
