#include "libft.h"

int ft_strncmp(const char *s1, const char*s2, size_t n)
{
    unsigned int i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        if (!s1[i] || !s2[i])
            break;
        i++;
    }
    return (0);
}

// int main()
// {
//     char str1[] = "makarena";
//     char str2[] = "mekarena";

//     printf("%d\n", ft_strncmp(str1, str2, 10));

//     char str11[] = "mekarena";
//     char str22[] = "makarena";

//     printf("%d\n", ft_strncmp(str11, str22, 10));

//     char str111[] = "makarena";
//     char str222[] = "makarena";

//     printf("%d\n", ft_strncmp(str111, str222, 10));

//     char str1111[] = "makare";
//     char str2222[] = "makarena";

//     printf("%d\n", ft_strncmp(str1111, str2222, 10));
// }