/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:32:15 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 22:02:12 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fits_int(char *s)
{
	size_t	len;
	char	*num;
	int		res;

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
			if (j != i && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int	count_words(char const *s, char c)
{
	unsigned int	words;
	unsigned int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || !s[i + 1])
				words++;
			i++;
		}
	}
	return (words);
}

int	valid_input(int argc, char *argv[])
{
	static int	i = 1;
	int			zeros;

	if (argc == 2 && i == 1)
	{
		i = 0;
		return (valid_input(count_words(argv[1], ' '), ft_split(argv[1], ' ')));
	}
	zeros = 0;
	while (argv[i])
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
