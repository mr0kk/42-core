/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:03:26 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/08 16:26:35 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
    %c - character 
    %s - string
    %f - float 
    %lf - double 
    %d - intiger 

    %.1 - deciman precision
    %1 - minimmum fild width
    %- - left align

    va_list args;  
    va_start(args, count);
    va_arg(args, int);
    va_end(args); 

    c → Character (char)
    s → String (char *)
    p → Pointer (memory address, typically printed in hexadecimal)
    d → Signed decimal integer (int)
    i → Signed decimal integer (same as d, used interchangeably)
    u → Unsigned decimal integer (unsigned int)
    x → Unsigned hexadecimal integer (lowercase, e.g., 0xabc)
    X → Unsigned hexadecimal integer (uppercase, e.g., 0xABC)
    % → Prints a literal % character 
*/

int read_format(const char f, va_list args)
{
    if (f == 'c')
        return(ft_putchar(va_arg(args, int)));
    else if (f == 's')
        return(ft_putstr(va_arg(args, char *)));
    else if (f == 'p')
        return (put_pointer(va_arg(args, uintptr_t)));
    else if (f == 'd' || f == 'i')
        return (put_int(va_arg(args, int)));
    else if (f == 'u')
        return (put_u_int(va_arg(args, unsigned int)));
    else if (f == 'x' || f == 'X')
        return (put_hex(va_arg(args, unsigned int), f));
    else if (f == '%')
        return (ft_putchar('%'));
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int length;
    size_t  i;
    
    if (!format)
        return (-1);
    length = 0;
    i = 0;
    va_start(args, format);
    
    while(format[i])
    {
        if (format[i] == '%')
        {
            length += read_format(format[i+1], args);
            i++;
        }
        else
            length += ft_putchar(format[i]);
        i++;
    }
    va_end(args);    
    return (length);
}
