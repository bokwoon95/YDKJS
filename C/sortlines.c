#include <stdio.h>
#include <string.h>
#include "allocafree.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int myreadlines(char *lineptr[], int maxlines);
void mywritelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

int main(int argc, char *argv[])
{
	int nlines;

	if ((nlines = myreadlines(lineptr, MAXLINES) >= 0)) {
		myqsort(lineptr, 0, nlines-1);
		mywritelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
	return 0;
}

#define MAXLEN 1000
int mygetline(char *, int);
char *alloc(int);

int myreadlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void mywritelines(char *lineptr[], int nlines) {
	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}

int mygetline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void myqsort(char *v[], int left, int right) {
	int i, last;
	void myswap(char *v[], int i, int j);

	if (left >= right) {
		return;
	}
	myswap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0) {
			myswap(v, ++last, i);
		}
	}
	myswap(v, left, last);
	myqsort(v, left, last-1);
	myqsort(v, last+1, right);
}

void myswap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
