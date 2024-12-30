/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:12 by rmrok             #+#    #+#             */
/*   Updated: 2024/12/30 10:22:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
#include <stdlib.h>
# include <string.h>
#include <limits.h>
#include <stdint.h>

int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int ft_isascii(int c);
int		ft_isprint(char c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t ft_strlcpy(char *dest, const char *src, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
int ft_strncmp(const char *s1, const char*s2, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *small, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_atoi(const char *nptr);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
void *ft_calloc(size_t nmemb, size_t size);
#endif