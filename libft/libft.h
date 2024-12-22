/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:12 by rmrok             #+#    #+#             */
/*   Updated: 2024/12/22 18:38:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
#include <stdlib.h>
# include <string.h>
#include <limits.h>

int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int ft_isascii(int c);
int		ft_isprint(char c);
size_t	ft_strlen(char *str);
void	*ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);

int ft_tolower(int c);
int ft_toupper(int c);
int ft_atoi(const char *nptr);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);

#endif