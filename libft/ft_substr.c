/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:45:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/01/03 12:45:37 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	unsigned int i;

	i = 0;
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);

	while (i < len && s[start])
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
//     char s[] = "hello, world!";
//     char *ptr;

//     ptr = ft_substr(s, 5, 7);
//     printf("%s\n", ptr);
// }