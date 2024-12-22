#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    i = 0;
    while(i < n)
    {
        d[i] = s[i];
        i++;
    }

    return (dest);
}

// int main(void)
// {
//     char test1[] = "12345";
//     char test2[] = "6789g";

//     memcpy(test2, test1, 3); 

//     printf("test2: %s\n", test2);

//     char test3[] = "12345";
//     char test4[] = "6789g";

//     memcpy(test4, test3, 3); 

//     printf("test2: %s\n", test2);
// }
