#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned int i;
    unsigned char *str1;
    unsigned char * str2;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    i = 0;

    if (n == 0)
        return (0);
    while (i < n)
    {
        printf("s1: %c\ts2: %c\n", *str1, *str2);
        if (*str1 != *str2)
            return (*str1 - *str2);
        if (!str1 || !str2)
            break;
        str1++;
        str2++;
        i++;
    }
    return (0);
}

// int main()
// {
//    char str1[15];
//    char str2[15];
//    int ret, ret2;

//    memcpy(str1, "ABCDEF", 6);
//    memcpy(str2, "ABCDEF", 6);

//    ret = memcmp(str1, str2, 10);
//    ret2 = ft_memcmp(str1, str2, 10);

//    printf("memcmp:\t\t%d\n", ret);
//    printf("ft_memcmp:\t%d\n", ret2);
// }