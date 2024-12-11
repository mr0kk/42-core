#include "libft.h"

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1024);
	return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1024);
	return (0);
}

int	ft_isprint(char c)
{
	if (c > '~' || c < ' ')
		return (0);
	return (1024);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}


int	main(void)
{
	// printf("%d  %d\n", ft_isalpha('A'), isalpha('A'));
	// printf("%d  %d\n", ft_isalpha('a'), isalpha('a'));
	// printf("%d  %d\n", ft_isalpha('3'), isalpha('3'));
	// printf("%d  %d\n", ft_isalpha('>'), isalpha('>'));
	// printf("%d  %d\n", ft_isalpha('2'), isalpha('2'));
	// printf("%d  %d\n", ft_isalpha('.'), isalpha('.'));
	// printf("%d  %d\n", ft_isalpha(' '), isalpha(' '));
	// printf("\n");
	// printf("%d  %d\n", ft_isdigit('A'), isdigit('A'));
	// printf("%d  %d\n", ft_isdigit('a'), isdigit('a'));
	// printf("%d  %d\n", ft_isdigit('3'), isdigit('3'));
	// printf("%d  %d\n", ft_isdigit('>'), isdigit('>'));
	// printf("%d  %d\n", ft_isdigit('2'), isdigit('2'));
	// printf("%d  %d\n", ft_isdigit('.'), isdigit('.'));
	// printf("%d  %d\n", ft_isdigit(' '), isdigit(' '));
	// printf("\n");
	printf("%lu\t%lu\n", strlen("napis"), ft_strlen("napis"));
	printf("%lu\t%lu\n", strlen(""), ft_strlen(""));
	printf("%lu\t%lu\n", strlen(" "), ft_strlen(" "));
	return (0);
}
