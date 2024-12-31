#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    ft_putstr_fd(ft_itoa(n), fd);
}

// int main()
// {
//     int n = -2147483648;
//     int fd = open("test.txt",  O_WRONLY | O_CREAT | O_TRUNC);
//     ft_putnbr_fd(n, fd);
//     close(fd);
// }