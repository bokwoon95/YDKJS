#include <stdio.h>
#define ALLOCSIZE 10000
#define prp(expr) printf("%p\n", expr)
#define prl(expr) printf("%lu\n", expr)

static char allocbuf[ALLOCSIZE]; /* storage for next alloc */
static char *allocp = allocbuf; /* next free position */

/* int main(int argc, char *argv[]) */
/* { */
/* 	printf("%p\n", allocbuf); */
/* 	prp(allocbuf + ALLOCSIZE); */
/* 	prl(allocbuf + ALLOCSIZE - allocp); */
/* 	return 0; */
/* } */

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else { /* not enough room */
		return 0;
	}
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}
