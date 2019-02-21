#include <stdio.h>

void Strcat(char *s, char *t);

int main(int argc, char *argv[])
{
	/* lame; the caller needs to make sure that it allocates enough space in
	 * the first character array to concatenate in the second character array.
	 * While it could still work without that precaution, the official C std
	 * specifies that it will be an 'undefined behavior' */
	char s1[50] = "four score and ";
	char s2[] = "seven years ago";
	Strcat(s1, s2);
	printf("%s\n", s1);
	return 0;
}

void Strcat(char *s, char *t) {
	while (*s)
		s++;
	while ((*s++ = *t++))
		;
	*s = '\0';
}
