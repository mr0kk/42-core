/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/22 23:55:26 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

# include "get_next_line.h"

char	*handle_leftovers(char **leftovers)
{
	char	*res;
	char	*tmp;
	char	*new_leftovers;
	size_t	res_len;

	if (!(*leftovers))
		return (NULL);
	tmp = ft_strchr(*leftovers, '\n');
	if (!tmp)
	{
		res = ft_strdup(*leftovers);
		free(*leftovers);
		*leftovers = NULL;
		return (res);
	}
	res_len = tmp - *leftovers;
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, *leftovers, res_len + 1);
	new_leftovers = ft_strdup(tmp);
	free(*leftovers);
	*leftovers = ft_strdup(new_leftovers);
	free(new_leftovers);
	return (res);
}

char	*create_res(char *buff, char *tmp)
{
	char	*res;
	size_t	res_len;

	res_len = ft_strlen(buff) - ft_strlen(tmp);
	printf("\nres_len: %zu\n", res_len);
	printf("buff_len: %zu\n", ft_strlen(buff));
	printf("tmp_len: %zu\n\n", ft_strlen(tmp));
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, buff, res_len + 1);
	printf("res[0]: %d\n", res[0]);
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

	printf("\n----------------------------\n");

	printf("leftovers: |%s|\n", leftovers);

	res = handle_leftovers(&leftovers);
	
	printf("res: |%s|\n", res);

	if (ft_strchr(res, '\n'))
		return (res);

	printf("res: |%s|\n", res);
	printf("leftovers: |%s|\n", leftovers);
	
	
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL); // maybe also free(res)?
	read_fd = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	printf("buff: |%s|\n", buff);
	printf("buff[0]: %d\n", buff[0]);
	tmp = ft_strchr(buff, '\n');
	printf("tmp: |%s|\n", tmp);

	if (tmp)
	{
		res = ft_strjoin(res, create_res(buff, tmp));
		leftovers = ft_strdup(tmp);
		free(buff);
		return (res);
	}
	while (!tmp && read_fd == BUFFER_SIZE)
	{
		new_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!new_buff)
			return (NULL);
		read_fd = read(fd, new_buff, BUFFER_SIZE);
		tmp = ft_strjoin(buff, new_buff);
		free(new_buff);
		free(buff);
		buff = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strchr(buff, '\n');
	}
	printf("read_fd: %d\n", read_fd);
	printf("buff: |%s|\n", buff);
	printf("tmp: |%s|\n", tmp);
	if (read_fd < BUFFER_SIZE)
	{
		res = ft_strjoin(res, buff);
		free(buff);
		return (res);
	}
	printf("\n----------------------------\n");
	return (NULL);
}

int main()
{
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

	
	res = get_next_line(fd);
	printf("\n<------------III-------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");

	res = get_next_line(fd);
	printf("\n<------------IV--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");

	res = get_next_line(fd);
	printf("\n<-------------V--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");
	
	res = get_next_line(fd);
	printf("\n<-------------VI--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");

	res = get_next_line(fd);
	printf("\n<-------------VII--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");

	res = get_next_line(fd);
	printf("\n<-------------VIII--------------->\n");
	printf("%s", res);
	printf("\n<----------------------------->\n");

	free(res);
	close(fd);
	return (0);
}
