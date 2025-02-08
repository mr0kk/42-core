/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:02:13 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/08 16:05:39 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	put_pointer(unsigned long long ptr);
int	put_int(int num);
int	put_u_int(unsigned int num);
int	put_hex(unsigned int num, char f);
char	*hex_conv(unsigned long num, char f);

#endif				