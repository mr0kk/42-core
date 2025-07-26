#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	int	i = 0;
	int	j = 0;
	char	*res;

	while (s[i])
	{
		j = 0;
		while (s[i] != accept[j] && accept[j])
			j++;
		if (accept[j])
		{
			res = (char *)s + i;
			return (res);
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *s = "12435D232333";
	char *accept = "GHTD";

	printf("strpbrk:\t%s\n", strpbrk(s, accept));
	printf("ft_strpbrk:\t%s\n", ft_strpbrk(s, accept));
}