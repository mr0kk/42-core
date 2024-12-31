#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    unsigned int i;
    
    i = 0;
    if (!s || !fd)
		return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

// int main()
// {
//     char str[] = "testowy tekst!";
//     int fd = open("test.txt",  O_WRONLY | O_CREAT | O_TRUNC);
//     ft_putstr_fd(str, fd);
//     close(fd);
// }