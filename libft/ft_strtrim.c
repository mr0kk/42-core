#include "libft.h"

unsigned int find_start(char const *s1, char const *set)
{
    unsigned int start;

    start = 0;
    while (start < ft_strlen(s1))
    {
        if (!ft_strchr(set, s1[start]))
            break;
        start++;
    }
    return (start);
}

unsigned int find_end(char const *s1, char const *set)
{
    unsigned int end;

    end = ft_strlen(s1) - 1;
    while (end > 0)
    {
        if (!ft_strchr(set, s1[end]))
            break;
        end--;
    }
    return (end); 
}

char *ft_strtrim(char const *s1, char const *set)
{
    char * res;
    unsigned int start;
    unsigned int end;

    if (!set)
        return (NULL);
    if (!s1)
    {
        res = (char *)malloc(1 * sizeof(char));
        res[0] = '\0';
        return (res);
    }
    start = find_start(s1, set);
    end = find_end(s1, set);
    printf("start: %u\n", start);
    printf("end: %u\n", end);
    printf("str len: %u\n", end - start + 2);
    if (start > end)
    {
        res = (char *)malloc(1 * sizeof(char));
        res[0] = '\0';
        return (res);
    }
    res = (char *)malloc((end - start + 2) * sizeof(char));
    if (res == NULL)
        return (NULL);
    ft_strlcpy(res, s1 + start, end - start + 2);
    return (res);
}

// int main(void)
// {
//     char s[] = "ABCDhello world!!ABCD";
//     char *ptr;

//     ptr = ft_strtrim(s, "ACBD");
//     printf("befotre trim:\t%s\n", s);
//     printf("after trim:\t%s\n", ptr);
//     int i = 0;
//     while (ptr[i])
//     {
//         printf("%c\t%d\n", ptr[i], ptr[i]);
//         i++;
//     } 
//     printf("%c\t%d\n", ptr[i], ptr[i]);
// }