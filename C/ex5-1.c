#include "ex5-1.h"
#include <stdio.h>
#include <ctype.h>
#include "getchungetch.c"

int main(void)
{
	char c;
	int ans = 0;
	int *pn = &ans;

	while ((c = getint(pn)) != EOF) {
		putchar(c);
	}
	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int c, sign;
	printf("THE VALUE OF *pn IS: %d\n", *pn);

	while (isspace(c = getch())) {
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			return -2;
		}
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	printf("THE CHARACTER c IS: %d\n", c);
	return c;
}
