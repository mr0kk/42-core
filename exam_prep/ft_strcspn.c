#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	int		j;
	int		bytes;

	bytes = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (bytes);
			
			j++;
		}
		bytes++;
		i++;
	}
	return (bytes);
}

int main(void)
{
	char	*s = "as1dfghjklA1234267848";
	char	*reject = "1234567890";
	char	*r2 = "1234567";


	printf("strcspn:\t%zu\n", strcspn(s, reject));
	printf("ft_strcspn:\t%zu\n", ft_strcspn(s, reject));
}