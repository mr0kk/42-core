#include "libft.h"

int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);

	// Fill 8 characters starting from str[13] with '.'
	memset(str + 13, '.', 8 * sizeof(char));

	printf("After memset():  %s", str);
	return (0);
}