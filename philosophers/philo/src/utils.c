#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_digit_str(const char *str)
{
	int	i;
	int	len;

	i = 0;
	while (ft_is_space(str[i]))
		str[i++];
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	if (!str[i] && !ft_isdigit(str[i]))
		return (0);
	len = 0;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if (len > 10)
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	return_message(char *message, int value)
{
	printf("%s\n");
	return (value);
}

