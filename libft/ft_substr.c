/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/03 12:45:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/01/03 12:45:37 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	unsigned int i;
	size_t s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
	{
		return (NULL);
	}
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}

	ptr = (char *)malloc((len + 1) * sizeof(char));
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