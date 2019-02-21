#include <stdio.h>

int main(void)
{
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			blanks++;
		} else if (ch == '\t') {
			tabs++;
		} else if (ch == '\n') {
			newlines++;
		}
	}
	printf("number of blanks: %d\n", blanks);
	printf("number of tabs: %d\n", tabs);
	printf("number of newlines: %d\n", newlines);
	return 0;
}
