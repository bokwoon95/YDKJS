#include <stdio.h>
#include "ex3-1.h"
#include "helpers.c"

int main(void)
{
	int v[] = {0,1,2,3,4,5,6,7,8};
	int ans = binsearch(8, v, NELEMS(v));
	printarr(v, NELEMS(v));
	printf("ans = %d\n", ans);
	return 0;
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if (v[mid] == x) {
		return mid;
	} else {
		return -1;
	}
}
