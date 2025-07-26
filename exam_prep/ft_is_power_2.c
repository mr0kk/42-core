#include <stdio.h>

int		ft_is_power_2(unsigned int n)
{
	int res;

	res = 1;
	while (res <= n)
	{
		if (res == n)
			return (1);
		res *= 2;
	}
	return (0);

}

int main()
{
	printf("%d\n", ft_is_power_2(1));
	printf("%d\n", ft_is_power_2(2));
	printf("%d\n", ft_is_power_2(3));
	printf("%d\n", ft_is_power_2(4));
	printf("%d\n", ft_is_power_2(128));
}