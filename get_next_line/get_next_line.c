/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:07 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/18 20:55:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	find_end(char *s, size_t len)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*new_buff(char *buff, int index)
{
	char	*new_buffer;
	int		i;
	
	new_buffer = (char *)malloc((index + BUFFER_SIZE + 1) * sizeof(char));
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (i <= index)
	{
		new_buffer[i] = buff[i];
		i++;
	}
	return (new_buffer);
}

char	*create_res(char *buff, int n_index)
{
	char	*res;
	int		i;
	
	res = (char *)malloc((n_index + 2) * sizeof(char));
	if(!res)
		return (NULL);
	i = 0;
	while (i <= n_index)
	{
		res[i] = buff[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*read_leftovers(char *buff, int index)
{
	char	*s;
	int		end;
	int		i;

	end = BUFFER_SIZE - index;
	s = (char *)malloc((end + 1) * sizeof(char));
	if(!s)
		return (NULL);
	i = 0;
	while (i < end)
	{
		s[i] = buff[index];
		i++;
		index++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}


char	*resize_buff(char *buff, int multiplier)
{
	char	*new_buff;
	int		i;

	new_buff = (char *)malloc((multiplier * BUFFER_SIZE + 1) * sizeof(char));
	if (!new_buff) 
		return (buff); // im not sure if its right
	i = 0;
	while (i < BUFFER_SIZE)
	{
		new_buff[i] = buff[i];
		i++;
	}
	new_buff[i] = '\0';
	// printf("\n---------------------\n");
	// printf("new_buff in function: \n%s", new_buff);
	// printf("\ntest: %s\n", new_buff + 5);
	// printf("\n---------------------\n");
	free(buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char	*new_buff;
	char		*buff;
	char		*res;
	int		read_fd;
	int n_index;
	
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_fd = read(fd, buff, BUFFER_SIZE);
	
	n_index = find_end(buff, read_fd);

	printf("read_file: %d\n", read_fd);
	printf("n_index: %d\n", n_index);
	
	int i = 2;
	printf("buff:\n%s\n", buff);
	printf("\n<--------------------->\n");
	int j = BUFFER_SIZE;
	while (n_index <= 0 && read_fd == BUFFER_SIZE)
	{
		buff = resize_buff(buff, i);
		read_fd = read(fd, buff + j, BUFFER_SIZE);
		n_index = find_end(buff, read_fd);
		printf("\n---------------------\n");
		printf("\ti = %i\t\n", i);
		printf("buff: \n%s\n", buff);
		printf("read_file: %d\n", read_fd);
		printf("n_index: %d\n", n_index);
		printf("buff len: %zu\n", strlen(buff));
		printf("\n---------------------\n");
		i++;
		j += BUFFER_SIZE;
	}
	
	return (buff);
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
