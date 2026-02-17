#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t res = 0;
	if (!s)
		return (res);
	while(s[res])
		res++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	if (!s)
		return (res);
	while(s)
	{
		if (*s == (char)c)
		{
			res = (char *)s;
			return (res);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	res = NULL;
	if (!s)
		return (res);
	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\n';
	return (res);
}

size_t	ft_strlcpy(const char *src, char *dest, size_t size)
{
	size_t	src_len;
	size_t	i;

	stc_len = 0;
	while (src(src_len))
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	long	len1 = (long)ft_strlen(s1);
	long	len2 = (long)ft_strlen(s2);
	char	*res = NULL;
	long	i;

	if (!s1 && !s2)
		return (res);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + len1] = s2[i];
		i++;
	}
	res[len1 + i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char	*tmp;
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	line = get_next_line(fd);
	int i = 0;
	while (line && i < 5)
	{
		printf("i = %d\n", i);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}