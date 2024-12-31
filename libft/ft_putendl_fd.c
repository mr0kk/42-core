#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    unsigned int i;
    char c;
    
    i = 0;
    if (!s || !fd)
		return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
    c = '\n';
    write(fd, &c, 1);
}

// int main()
// {
//     char str[] = "testowy tekst!";
//     int fd = open("test.txt",  O_WRONLY | O_CREAT | O_TRUNC);
//     ft_putendl_fd(str, fd);
//     close(fd);
// }