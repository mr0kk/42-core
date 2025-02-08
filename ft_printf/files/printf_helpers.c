/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:01:58 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/08 13:32:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int put_pointer(unsigned long long ptr)
{
    int len;

    len = 2;
    write(1, "0x", 2);
    len += ft_putstr(hex_conv(ptr, 'x'));
    return (len);
}

int put_int(int num)
{
    int len;
    
    len = ft_putstr(ft_itoa(num));
    return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int    ft_putstr(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
	{
		write(1, &s[i], 1);
		i++;
    }
    return (i);
}