#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);
int in(char c, char s[]);

int main(void)
{
	int ans = any("0123456", "0");
	printf("ans = %d\n", ans);
	return 0;
}

int any(char s1[], char s2[]) {
	int i;
	int len_s1 = strlen(s1);
	for (i = 0; i < len_s1; ++i) {
		if (in(s1[i], s2)) {
			return i;
		}
	}
	return -1;
}

int in(char c, char s[]) {
	int i;
	int len = strlen(s);
	for (i = 0; i < len; ++i) {
		if (s[i] == c) {
			return 1;
		}
	}
	return 0;
}
