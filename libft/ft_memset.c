#include "libft.h"


void *ft_memset(void *str, int c, size_t n)
{
	while (n)
	{
		str = c;
		*str++;
		n--;
	}
	return (str);
}

int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);

	// Fill 8 characters starting from str[13] with '.'
	memset(str + 13, '.', 8 * sizeof(char));

	printf("After memset():  %s", str);



	char str2[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore ft_memset(): %s\n", str2);

	// Fill 8 characters starting from str[13] with '.'
	ft_memset(str2 + 13, '.', 8 * sizeof(char));

	printf("After ft_memset():  %s", str2);

	return (0);
}