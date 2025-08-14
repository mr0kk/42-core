/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:32:15 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/14 21:42:55 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	fits_int(char *s)
{
	size_t	len;
	char	*num;
	int res;
	
	num = ft_strtrim(s, "+ \t");
	len = ft_strlen(num);
	if (num[0] == '-') 
	{
		if (len > 11)
			return (0);
		else if (len == 11)
			res = ft_strncmp("-2147483648", num, len);
	}
	else if (len > 10)
		return (0);
	else if (len == 10)
		res = ft_strncmp("2147483647", num, len);
	free(num);
	return (!(res < 0));
}

int	is_number(char *s)
{
	int		i;
	char	*num;

	num = ft_strtrim(s, " \t");
	i = 0;
	if (is_sign(num[0]))
		i++;
	while (num[i])
	{
		if (!is_digit(num[i]))
			return (0);
		i++;
	}
	free(num);
	return (1);
}

int	nbr_cmp(const char *s1, const char *s2)
{
	char	*num1;
	char	*num2;
	int		i;
	int		j;
	int		res;

	num1 = ft_strtrim(s1, " \t");
	num2 = ft_strtrim(s2, " \t");
	i = 0;
	j = 0;
	if (num1[0] == '+')
		if (num2[i] != '+')
			i++;
	else
		if (num2[0] == '+')
			j++;
	while (num1[i] == num2[j] && (num1[i] && num2[j]))
	{
		i++;
		j++;
	}
	res = (unsigned char)num1[i] - (unsigned char)num2[j];
	free(num1);
	free(num2);
	return (res);
}

int	have_duplicates(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (j != i && !nbr_cmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_input(int argc, char *argv[])
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		if (!fits_int(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) == 0)
			zeros++;
		i++;
	}
	if (zeros > 1)
		return (0);
	if (have_duplicates(argv, argc))
		return (0);
	return (1);
}
