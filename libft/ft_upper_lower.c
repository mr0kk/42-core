/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_lower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:45:40 by rmrok             #+#    #+#             */
/*   Updated: 2025/01/03 12:45:40 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int main(void)
// {
//     printf("%c\n", ft_toupper('a'));
//     printf("%c\n", ft_toupper('A'));
//     printf("%c\n", ft_toupper('0'));
//     printf("%c\n", ft_toupper('.'));

//     printf("%c\n", ft_tolower('a'));
//     printf("%c\n", ft_tolower('A'));
//     printf("%c\n", ft_tolower('0'));
//     printf("%c\n", ft_tolower('.'));
// }