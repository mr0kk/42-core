#include "libft.h"

static int count_len(int n)
{
    int len;

    len = 0;
    while (n)
    {
        len++;
        n /= 10;
    }
    return (len);
}

static void ft_swap(char *res, int len)
{
    int i;
    char tmp;

    i = 0;
    while (i < len)
    {
        tmp = res[i];
        res[i] = res[len];
        res[len] = tmp;
        i++;
        len--;
    }
}

char *ft_itoa(int n)
{
    char *res;
    int len;
    int i;

    i = 0;
    len = count_len(n);
    res = (char *)malloc(len * sizeof(char) + 1);
    if (res == NULL)
        return (NULL);
    while (n)
    {
        res[i] = (char)(n % 10 + 48);
        n /= 10;
        i++;
    }
    ft_swap(res, len - 1);
    return (res);
}

// int main()
// {
//     int n = 123456789;
//     char *str;

//     str = ft_itoa(n);
//     printf("%s\n", str);
// }