#include "libft.h"

static int count_len(int n)
{
    int len;

    len = 0;
    if (n < 0)
    {
        len++;
        n *= -1;
    }
    while (n)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char *ft_itoa(int n)
{
    char *res;
    int len;
    
    if (n == 0)
        return ("0");
    if (n == -2147483648)
        return ("-2147483648");
    len = count_len(n);
    res = (char *)malloc((len + 1) * sizeof(char));
    if (res == NULL)
        return (NULL);
    res[len] = '\0';
    if (n < 0)
    {
        res[0] = '-';
        n *= -1;
    }
    while ((len - 1) >= 0 && n > 0)
    {
        res[len - 1] = n % 10 + 48;
        n /= 10;
        len--;
    }
    return (res);
}

// int main()
// {
//     int tests[] = {
//         123456789,
//         -123456789,
//         -2147483648,
//         2147483647,
//         0,
//         23
//     };
//     char *str;
//     int i = 0;
//     while (i < sizeof(tests) / sizeof(int))
//     {
//         printf("number:\t\t%d\n", tests[i]);
//         str = ft_itoa(tests[i]);
//         printf("as ascii:\t%s\n", str);
//         printf("------------------------------\n");
//         i++;
//     }
//     free(str);
// }