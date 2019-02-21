#include "ex3-2.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char s[] = "This is some shit\t\n\t\nyeet";
	char t[100];
	escape(s, t);
	printf("%s\n", t);
	return 0;
}

void escape(char s[], char t[]) {
	int i,j;
	char ch;

	i = j = 0;
	while ((ch = s[i++]) != '\0') {
		switch (ch) {
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = ch;
		}
	}
	t[j] = '\0';
}
