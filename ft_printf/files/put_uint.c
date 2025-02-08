/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:09 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/08 16:26:46 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*res;
	int				len;
	unsigned int	num;

	len = count_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	num = (unsigned int)n;
	if (n < 0)
	{
		res[0] = '-';
		num = (unsigned int)n * -1;
	}
	res[len] = '\0';
	while (len - 1 >= 0 && num > 0)
	{
		res[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (res);
}

int put_u_int(unsigned int num)
{
    int len;
    
    len = ft_putstr(ft_utoa(num));
    return (len);
}