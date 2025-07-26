#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strdup(char *src)
{
	int len = ft_strlen(src);
	char *res;
	int i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *test = "marakuja";
// 	char *res;


// 	res = ft_strdup(test);
// 	printf("test:\t%p\n", test);
// 	printf("res:\t%p\n", res);
// }

