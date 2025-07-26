#include <string.h>
#include <stdio.h>

size_t ft_strspn(const char *s, const char *accept)
{
	int i;
	int j;
	int bytes;

	bytes = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j] != s[i] && accept[j])
			j++;
		if (accept[j])
		{
			bytes++;
			i++;
		}
		else
			return (bytes);
	}
	return (bytes);
}

int main(void)
{
	char *s = "1234267848as1dfghjklA1234267848";
	char *accept = "1234567890";

	printf("strspn:\t%zu\n", strspn(s, accept));
	printf("ft_strspn:\t%zu\n", ft_strspn(s, accept));
}