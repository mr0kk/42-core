/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/23 16:30:23 by marvin           ###   ########.fr       */
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
	res_len = tmp + 1 - *leftovers;
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, *leftovers, res_len + 1);
	new_leftovers = ft_strdup(tmp + 1);
	free(*leftovers);
	*leftovers = ft_strdup(new_leftovers);
	free(new_leftovers);
	return (res);
}

char	*create_res(char *buff, char *tmp)
{
	char	*res;
	size_t	res_len;

	if (tmp)
		tmp += 1;
	res_len = ft_strlen(buff) - ft_strlen(tmp);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, buff, res_len + 1);
	return (res);
}

char *read_buff(int fd, int *read_fd)
{
	char	*buff;
	
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	*read_fd = read(fd, buff, BUFFER_SIZE);
	if (*read_fd <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[*read_fd] = '\0';
	return (buff);
}

char	*handle_buffer(int fd)
{
	char	*buff;
	char	*new_buff;
	char	*tmp;
	int		read_fd;
	
	buff = read_buff(fd, &read_fd);
	if (!buff)
		return (NULL);
	tmp = ft_strchr(buff, '\n');
	while (!tmp && read_fd == BUFFER_SIZE)
	{
		new_buff = read_buff(fd, &read_fd);
		if (!new_buff)
			return (buff);
		tmp = ft_strdup(buff);
		free(buff);
		buff = ft_strjoin(tmp, new_buff);
		free(tmp);
		free(new_buff);
		tmp = ft_strchr(buff, '\n');
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*leftovers = NULL;
	char		*buff;
	char		*tmp;
	char		*res;

	res = handle_leftovers(&leftovers);
	if (ft_strchr(res, '\n'))
		return (res);	
	buff =  handle_buffer(fd);
	if (!buff)
		return (res);
	tmp = ft_strdup(buff);
	free(buff);
	buff = ft_strjoin(res, tmp);
	free(tmp);
	free(res);
	tmp = ft_strchr(buff, '\n');
	if (tmp)
		leftovers = ft_strdup(tmp + 1);
	res = create_res(buff, tmp);
	free(buff);
	return (res);
}

void tester(char *file_name)
{
	int fd = open(file_name, O_RDONLY | O_CREAT);
	char *res;
	
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}

	free(res);
	close(fd);
}

int main(int argc, char *argv[])
{	
	if (argc == 2)	
		tester(argv[1]);
	else
		tester("test3.txt");
	
	return (0);
}
