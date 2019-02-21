#include <stdio.h>
#include <math.h>

void checkint(float z);

int main(void)
{
	float fahr, celcius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 2;

	fahr = lower;
	printf("fahrenheit\t celcius\n");
	while (fahr <= upper) {
		celcius = (5.0/9.0) * (fahr-32.0);
		printf("%.f\t\t %.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
	return 0;
}

void checkint(float z) {
	if (fabsf(rintf(z) - z) <= 0.00001f) {
		printf("%f is an integer\n", z);
	} else {
		printf("%f is a fraction\n", z);
	}
}
