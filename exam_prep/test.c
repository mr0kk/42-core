#include <string.h>
#include <stdio.h>

int main()
{
	char *s = "ala ma kota";
	char *charset = "ala";

	printf("%lu\n", strcspn(s, charset));
	printf("%lu\n", strspn(s, charset));

	int seen[100] = {0};
	printf("%d\n", seen[2]);
}