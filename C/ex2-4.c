#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);
int in(char c, char s[]);

int main(void)
{
	char s1[] = "The quick brown fox jumps over the lazy dog";
	squeeze(s1, "eo");
	printf("%s\n", s1);
	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;
	for (i = j = 0; s1[i] != '\0' ; ++i) {
		if (!in(s1[i], s2)) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

int in(char c, char s[]) {
	int i;
	int len = strlen(s);
	int present = 0;
	for (i = 0; i < len; ++i) {
		if (s[i] == c) {
			present = 1;
			break;
		}
	}
	return present;
}
