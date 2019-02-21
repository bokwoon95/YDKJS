#include "ex5-2.h"
#include <stdio.h>
#include <ctype.h>
#include "getchungetch.c"

int main(void)
{
	char c;
	float ans = 0;
	float *pn = &ans;

	while ((c = getfloat(pn)) != EOF) {
		putchar(c);
	}
	return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(float *pn) {
	int c, sign, dpt;
	printf("THE VALUE OF *pn IS: %f\n", *pn);

	while (isspace(c = getch())) {
		;
	}

	/* if the nonspace character c that broke the loop is not: a digit, EOF, +
	 * or -, then ungetch(c) and return immediately*/
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	/* initialize the sign */
	sign = (c == '-') ? -1 : 1;

	/* if c is a + or -, get the next character */
	if (c == '+' || c == '-') {
		c = getch();
		/* if the next character is not a digit, return immediately */
		if (!isdigit(c)) {
			ungetch(c);
			return 0;
		}
	}
	/* while the next character is still a digit, keep reading it in */
	for (*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}
	if (c == '.') {
		dpt = 0;
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			return 0;
		}
		for (; isdigit(c); c = getch()) {
			/* TODO: WOW this part is hard. I don't know why the addition is constantly refusing to work, ie I have 123 + 0.12999 or whatever and it always still ends up as 123 in the *pn variable */
			*pn = *pn + (float)(c - '0')/(10 * ++dpt);
		}
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	printf("THE CHARACTER c IS: %d\n", c);
	return c;
}
