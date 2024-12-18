/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstaff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:24 by rmrok             #+#    #+#             */
/*   Updated: 2024/12/18 16:41:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalnum(char c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int	ft_isprint(char c)
{
	return (c >= '!' && c <= '~');
}

int main()
{
	char c;

	c = '1';
	printf("char\tfunc()\tft_funct()\n");
	printf("%c\t%d\t%d\n", c, isalpha(c), ft_isalpha(c));
	c = 'a';
	printf("%c\t%d\t%d\n", c, isalpha(c), ft_isalpha(c));
	c = '\t';
	printf("%c\t%d\t%d\n", c, isprint(c), ft_isprint(c));
	c = ' ';
	printf("%c\t%d\t%d\n", c, isprint(c), ft_isprint(c));
	c = 'd';
	printf("%c\t%d\t%d\n", c, isprint(c), ft_isprint(c));	
	return (0);
}