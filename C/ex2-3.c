#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char str[]);

int main(void)
{
	int ans1 = htoi("1A4");
	int ans2 = htoi("138D5");
	printf("1A4 = %d\n", ans1);
	printf("0x138D5 = %d\n", ans2);
	return 0;
}

int htoi(char str[]) {
	char ch;
	int i = strlen(str);
	int starting_idx = 0;
	int sum = 0;
	int power = 0;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		starting_idx = 2;
	}
	while (--i >= starting_idx) {
		ch = str[i];
		if (ch >= 'A' && ch <= 'F' ) {
			sum += (ch - 'A' + 10) * pow(16, power++);
		} else if (ch >= '0' && ch <= '9') {
			sum += (ch - '0') * pow(16, power++);
		} else {
			return -1;
		}
	}
	return sum;
}
