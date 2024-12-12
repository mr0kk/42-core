/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:01 by rmrok             #+#    #+#             */
/*   Updated: 2024/12/11 23:49:02 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// printf("%d  %d\n", ft_isalpha('A'), isalpha('A'));
	// printf("%d  %d\n", ft_isalpha('a'), isalpha('a'));
	// printf("%d  %d\n", ft_isalpha('3'), isalpha('3'));
	// printf("%d  %d\n", ft_isalpha('>'), isalpha('>'));
	// printf("%d  %d\n", ft_isalpha('2'), isalpha('2'));
	// printf("%d  %d\n", ft_isalpha('.'), isalpha('.'));
	// printf("%d  %d\n", ft_isalpha(' '), isalpha(' '));
	// printf("\n");
	// printf("%d  %d\n", ft_isdigit('A'), isdigit('A'));
	// printf("%d  %d\n", ft_isdigit('a'), isdigit('a'));
	// printf("%d  %d\n", ft_isdigit('3'), isdigit('3'));
	// printf("%d  %d\n", ft_isdigit('>'), isdigit('>'));
	// printf("%d  %d\n", ft_isdigit('2'), isdigit('2'));
	// printf("%d  %d\n", ft_isdigit('.'), isdigit('.'));
	// printf("%d  %d\n", ft_isdigit(' '), isdigit(' '));
	// printf("\n");
	printf("%lu\t%lu\n", strlen("napis"), ft_strlen("napis"));
	printf("%lu\t%lu\n", strlen(""), ft_strlen(""));
	printf("%lu\t%lu\n", strlen(" "), ft_strlen(" "));
	return (0);
}