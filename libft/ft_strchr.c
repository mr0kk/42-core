#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *ans;

    ans = NULL;
    while (*s)
    {
        if (*s == c)
        {
            ans = (char *)s;
            return (ans);
        }
        s++;
    }
    if (c =='\0')
        return (char *)s;
    return (NULL);
}

// int main(void)
// {
//     char *test = "ala ma kota";
//     printf("%s\n", ft_strchr(test, 'm'));
//     printf("%s\n", strchr(test, 'm'));

//     if (strchr(test, 'x') == NULL)
//         printf("NULL\n");
//     if (ft_strchr(test, 'x') == NULL)
//         printf("NULL\n");
// }