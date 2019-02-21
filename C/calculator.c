/* #include "calculator.h" */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define PRINT '1'
#define DUPLICATE '2'
#define SWAP '3'

void ungetch(int c);
int getch(void);
double pop(void);
void push(double f);
int getop(char s[]);
int main(void);

int main(void)
{
	int type;
	double op2, op3;
	char s[MAXOP];

	printf("RPN Calculator v1.0\n");
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;
			case PRINT:
				op2 = pop();
				printf("\tprint: %.8g\n", op2);
				push(op2);
				push(op2); // offset \n's pop()
				break;
			case DUPLICATE:
				op2 = pop();
				printf("\nduplicated: %.8g -> %.8g, %.8g\n", op2, op2, op2);
				push(op2);
				push(op2);
				push(op2); //offset \n's pop()
				break;
			case SWAP:
				op2 = pop();
				op3 = pop();
				push(op2);
				push(op3);
				push(op3); // offset \n's pop()
				printf("\tswapped: %.8g, %.8g -> %.8g, %.8g\n", op3, op2, op2, op3);
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	printf("Moriturus te saluto\n");
	return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getop(char s[]) {
	// This function is hard to reason about because it 'returns' a result by
	// modifying the array that's in the address that was passed in. Its actual
	// return value is simply a signal signifying what is inside the array.
	int i, c;

	// keep overwriting s[0] with c until c is not a space or a tab
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0'; // null terminate the array so that s is a valid string

	// check for special commands
	if (tolower(c) == 'p') return PRINT;
	if (tolower(c) == 'd') return DUPLICATE;
	if (tolower(c) == 's') return SWAP;

	// If non-space, non-tab character c is not a digit or a decimal, return
	// that character
	if (!isdigit(c) && c != '.') {
		return c;
	}

	// If encounter a digit, keep reading (& writing to s) until c is no longer
	// a digit
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	// If the non digit is a decimal point, continue reading for digits (&
	// writing to s) until c is no longer a digit
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	// Overwrite the last non-digit at index i with a null terminator
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}
