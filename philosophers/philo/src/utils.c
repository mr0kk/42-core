#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_digit_str(char *str)
{
	int i = 0;

	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	result;
	int				i;
	int				sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - 48);
	return ((int)result * sign);
}

size_t	ft_atosize(const char *nptr)
{
	size_t	result;
	int		i;

	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - 48);
	return (result);
}
