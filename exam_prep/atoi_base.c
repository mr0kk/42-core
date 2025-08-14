
int	leng(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	digit_to_int(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == digit)
			return (i);
		i++;
	}
	return (0);
}

int	is_base_ok(char *base)
{
	int	i;
	int	j;
	int	len;

	len = leng(base);
	i = -1;
	if (len < 2)
		return (0);
	while (++i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	i = -1;
	while (++i < len)
		if (base[i] == '-' || base[i] == '+')
			return (0);
	return (1);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus_counter;
	int	result;

	i = 0;
	result = 0;
	minus_counter = 0;
	while (str[i] <= ' ' || str[i] == 127)
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus_counter++;
	while (is_in_base(str[i], base))
		result = result * leng(base) + digit_to_int(str[i++], base);
	if (minus_counter % 2)
		return (result * -1);
	return (result);
}
#include <stdio.h>

int	main(void)
{
	char str[] = "ff";
	char base[] = "0123456789abcdef!>[]";

	int output;

	output = ft_atoi_base(str, base);
	printf("output: %d\n", output);

	output = ft_atoi_base("    ----+++-1001+101", "01");
	printf("output: %d\n", output);
}