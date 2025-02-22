/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/22 01:33:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*handle_leftovers(char *leftovers)
{
	char	*res;
	char	*tmp;
	size_t	res_len;
	int		i;

	if (!leftovers)
		return (NULL);
	tmp = ft_strchr(leftovers, '\n');
	if (!tmp)
	{
		res = ft_strdup(leftovers);
		free(leftovers);
		leftovers = NULL;
		return (res);
	}
	res_len = ft_strlen(leftovers) - ft_strlen(tmp);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
	{
		free(leftovers);
		return (NULL);
	}
	i = 0;
	while (i < res_len)
		res[i++] = leftovers[i];
	res[i] = '\0';
	free(leftovers);
	leftovers = NULL;
	leftovers = ft_strdup(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*leftovers = NULL;
	char		*buff;
	char		*tmp;
	char		*new_buff;
	char		*res;
	int			read_fd;

	
	tmp = handle_leftovers(leftovers);
	printf("\n----------------------------\n");
	printf("tmp(handle leftovers): |%s|\n", tmp);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (res);
	read_fd = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	printf("buff: |%s|\n", buff);
	printf("read_fd: %d\n", read_fd);
	printf("tmp(handle leftovers): |%s|\n", tmp);
	printf("tmp_len: %zu\n", ft_strlen(tmp));
	res = ft_strjoin(tmp, "");
	printf("res: |%s|\n", res);
	free(tmp);
	tmp = ft_strchr(buff, '\n');
	printf("tmp: |%s|\n", tmp);
	while (!tmp && read_fd == BUFFER_SIZE)
	{
		new_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!new_buff)
			return (NULL);
		read_fd = read(fd, new_buff, BUFFER_SIZE);
		new_buff[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(buff, new_buff);
		free(buff);
		free(new_buff);
		buff = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strchr(buff, '\n');
	}
	leftovers = ft_strdup(tmp);
	printf("leftovers: |%s|\n", leftovers);
	// free(tmp);
	int i = 0;
	int res_len = ft_strlen(buff) - ft_strlen(leftovers);
	printf("res_len: %d\n", res_len);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < res_len)
		res[i++] = buff[i];
	res[i] = '\0';
	free(buff);
	printf("\n----------------------------\n");
	return (res);
}

int main()
{
	int len;
	int fd = open("test3.txt", O_RDONLY | O_CREAT);
	char	*res;

	res = get_next_line(fd);
	printf("\n<-------------I--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");
	res = get_next_line(fd);
	printf("\n<-------------II-------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");
	printf("\n<------------III-------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");
	close(fd);
	return (0);
}
