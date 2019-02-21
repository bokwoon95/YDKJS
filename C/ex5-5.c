#include <stdio.h>
#include <string.h>

void Strncpy(char *dest, char *source, int num);
void Strncat(char *dest, char *source, int num);
int Strncmp(char *s1, char *s2, int num);

int main(int argc, char *argv[])
{
	char s1[100] = "beep beep I'm a sheep";
	char s2[] = "beep";
	/* Strncpy(s1, s2, 4); */
	/* Strncat(s1, s2, 4); */
	printf("%s\n", s1);
	int ans = Strncmp(s1, s2, 4);
	printf("%d\n", ans);
	return 0;
}

void Strncpy(char *dest, char *source, int num) {
	while (num-- > 0 && (*dest++ = *source++))
		;
}

void Strncat(char *s, char *t, int num) {
	while (*s) {
		s++;
	}
	while (num-- > 0 && *t) {
		*s = *t;
		s++ && t++;
	}
	*s ='\0';
}

int Strncmp(char *s1, char *s2, int num) {
	while (--num > 0 && *s1 == *s2) {
		s1++;
		s2++;
	}
	if (*s1 == '\0' || *s2 == '\0') {
		return 0;
	}
	return *s1 - *s2;
}
