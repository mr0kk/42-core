/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:10:00 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/08 16:26:39 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void swap_it(char *str)
{
    char    c;
    int len;
    int i;
    
    len = ft_strlen(str) - 1;
    i = 0;
    while (i < len)
    {
        c = str[i];
        str[i] = str[len];
        str[len] = c;
        i++;
        len--;
    }
}

char *hex_conv(unsigned long num, char f)
{
    int     i;
    char    *res;
    char    base[] = "0123456789abcdef";
    char    base2[] = "0123456789ABCDEF";
    
    res = (char *)malloc(17 * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (num)
    {
        if (f == 'x')
            res[i] = base[num % 16];
        else
            res[i] = base2[num % 16];
        num /= 16;
        i++;
    }
    res[i] = '\0';
    swap_it(res);
    return (res);
}

int put_hex(unsigned int num, char f)
{
    int len;
    
    if (num == 0)
        return (ft_putchar('0'));
    
    len = ft_putstr(hex_conv((unsigned long)num, f));
    
    return (len);
}
