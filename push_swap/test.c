#include <stdio.h>

void funkcja(char *s)
{
	s[0] = 'p';
	printf("%s\n", s);
}

int main(void)
{
	char tmp[] = "dupa";

	printf("%s\n", tmp);
	funkcja(tmp);
	printf("%s\n", tmp);
}