#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

// int main()
// {
// 	printf("len: %ld\n", ft_strlen("123456789"));
// }