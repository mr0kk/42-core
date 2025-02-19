/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/19 20:42:58 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *leftovers = NULL;
	char		*buff;
	char		*res;
	char		*new_buff;
	int			read_fd;
	int			i;

	if (leftovers)
	{
		// res = ft_strchr(leftovers, '\n');
		return (leftovers);
	}
	res = ft_strjoin(leftovers, "");
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_fd = read(fd, buff, BUFFER_SIZE);
	printf("buff: \n%s\n", buff);
	i = 2;
	leftovers = ft_strchr(buff, '\n');
	while (!leftovers && read_fd == BUFFER_SIZE)
	{
		new_buff = (char *)malloc((i * BUFFER_SIZE + 1) * sizeof(char));
		
	}
}

int main()
{
	int len;
	int fd = open("test.txt", O_RDONLY | O_CREAT);
	char	*res;
	
	res = get_next_line(fd);
	printf("\n<---------------------------->\n");
	printf("%s", res);
	// res = get_next_line(fd);
	// printf("%s", res);
	close(fd);
	return (0);
}
