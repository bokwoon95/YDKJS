#include <stdio.h>

int strend(char *s, char *t);

int main(int argc, char *argv[])
{
	char s1[] = "Hit or miss, I guess they never miss huh.";
	char s2[] = "I guess they never miss huh.";
	int ans = strend(s1, s2);
	printf("ans = %d\n", ans);
	return 0;
}

int strend(char *s, char *t) {
	int result = 0;
	char *to;
	while (*s) {
		if (*s == *t) {
			to = t;
			while (*s == *t && *s != '\0') {
				s++;
				t++;
			}
			if (*t == '\0' && *s == '\0') {
				return 1;
			}
			t = to;
		}
		s++;
	}
	return result;
}
