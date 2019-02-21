#include <stdio.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void printarr(int arr[],size_t len);

/* int main(int argc, char *argv[]) */
/* { */
/* 	return 0; */
/* } */

void printarr(int arr[], size_t len) {
	int i;

	printf("[");
	for (i = 0; i < len; ++i) {
		printf("%d,",arr[i]);
	}
	printf("]\n");
}
