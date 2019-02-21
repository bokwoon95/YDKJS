#include <stdio.h>
#include "shellsort.h"
#include "helpers.c"

int main(void)
{
	int v[] = {0,9,8,7,6,5,4,3,2,1,10};
	shellsort(v, NELEMS(v));
	printarr(v, NELEMS(v));
	return 0;
}

void shellsort(int v[], size_t n) {
	int gap, i, j, temp;

	for (gap=n/2; gap>0; gap/=2) {
		for (i=gap; i<n; i++) {
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
