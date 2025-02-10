/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/10 14:05:32 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	count_line_len(int fd)
{
	size_t		len;
	int		i;
	char	c;

	len = 0;
	i = read(fd, &c, 1);
	while (i > 0 && c != '\n')
	{
		len++;
		i = read(fd, &c, 1);
	}
	return (len);
}

char	*get_next_line(int fd)
{
	size_t	line_len;
	size_t	i;
	int 	len;
	char	*res;
	char	c;
	

	line_len = count_line_len(fd);
	printf("line len: %zu\n", line_len);
	line_len = count_line_len(fd);
	printf("line len: %zu\n", line_len);
	// res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (!res)
	// 	return (NULL);
	// len = 1;
	// i = 0;
	// while (res[i] != '\n')
	// {
	// 	len = read(fd, &c, 1);
	// 	if (len <= 0)
	// 	{
	// 		free(res);
	// 		return (NULL);
	// 	}
	// 	res[i++] = c;
	// }
	// res[i + 1] = '\0';
	res = NULL;
	return (res);
}

int main()
{
	int len;
	int fd = open("test3.txt", O_RDONLY | O_CREAT);
	char	* res;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	// get_next_line(fd);
	// res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// res = get_next_line(fd);
	// while (res)
	// {
	// 	printf("%s", res);
	// 	res = get_next_line(fd);
	// }
	close(fd);
}