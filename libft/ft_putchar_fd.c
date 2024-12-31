#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

// int main()
// {
//     int fd = open("test.txt",  O_WRONLY | O_CREAT | O_TRUNC);
//     ft_putchar_fd('b', fd);
//     close(fd);
// }