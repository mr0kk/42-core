#include "libft.h"

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1024);
	else
		return (0);
}
int	main(void)
{
	printf("%d  %d\n", ft_isalpha('A'), isalpha('A'));
	printf("%d  %d\n", ft_isalpha('a'), isalpha('a'));
	printf("%d  %d\n", ft_isalpha('3'), isalpha('3'));
	printf("%d  %d\n", ft_isalpha('>'), isalpha('>'));
	printf("%d  %d\n", ft_isalpha('2'), isalpha('2'));
	printf("%d  %d\n", ft_isalpha('.'), isalpha('.'));
	printf("%d  %d\n", ft_isalpha(' '), isalpha(' '));
	printf("\n");
	printf("%d  %d\n", ft_isdigit('A'), isdigit('A'));
	printf("%d  %d\n", ft_isdigit('a'), isdigit('a'));
	printf("%d  %d\n", ft_isdigit('3'), isdigit('3'));
	printf("%d  %d\n", ft_isdigit('>'), isdigit('>'));
	printf("%d  %d\n", ft_isdigit('2'), isdigit('2'));
	printf("%d  %d\n", ft_isdigit('.'), isdigit('.'));
	printf("%d  %d\n", ft_isdigit(' '), isdigit(' '));
	return (0);
}
