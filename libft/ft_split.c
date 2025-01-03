/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:44:57 by rmrok             #+#    #+#             */
/*   Updated: 2025/01/03 12:44:57 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static unsigned int	count_words(char const *s, char c)
{
	unsigned int words;
	unsigned int i;

	i = 0;
	words = 1;
	while (i++ < ft_strlen(s))
		if (s[i] == c)
			words++;
	return (words);
}

static void	write_words(char **res, unsigned int words, char c, char const *s)
{
	unsigned int i;
	unsigned int j;
	unsigned int str_len;

	i = 0;
	j = 0;
	while (i < words)
	{
		str_len = 0;
		while (s[j] != c && s[j++])
			str_len++;
		res[i] = (char *)malloc(str_len * sizeof(char) + 1);
		if (res[i] == NULL)
			continue ;
		j -= str_len;
		ft_strlcpy(res[i++], s + j, str_len + 1);
		j += str_len + 1;
	}
	res[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char **res;
	unsigned int words;

	words = count_words(s, c);
	res = (char **)malloc(words * sizeof(char *) + 1);
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	write_words(res, words, c, s);
	return (res);
}

// int main()
// {
//     char s[] = ",owca,lubi,jesc,owoce,nie,wazne,jakie,";
//     char **ptr;

//     ptr = ft_split(s, ',');
//     int i = 0;
//     int j;
//     while (ptr[i])
//     {
//         j = 0;
//         while (ptr[i][j])
//         {
//             printf("%c", ptr[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// }