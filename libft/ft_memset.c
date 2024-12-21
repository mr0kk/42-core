/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:35 by rmrok             #+#    #+#             */
/*   Updated: 2024/12/15 00:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *str, int c, size_t n)
{
	printf("%ld\n", sizeof(c));
	printf("%ld\n", sizeof(str));
	printf("%d\n", *(char*)str);
	
	//return (str);
}

int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore memset(): %s\n", str);

	// Fill 8 characters starting from str[13] with '.'
	memset(str + 13, '.', 8 * sizeof(char));

	printf("After memset():  %s", str);

	char str2[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore ft_memset(): %s\n", str2);

	// Fill 8 characters starting from str[13] with '.'
	printf("before: %ld\n", sizeof(str2 + 13));
	ft_memset(str2 + 13, '.', 8 * sizeof(char));

	printf("After ft_memset():  %s", str2);

	printf("\n%c\n", 32);
	return (0);
}