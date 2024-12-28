#include "libft.h"


size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    unsigned int dest_len;
    unsigned int src_len;
    unsigned int dest_i;
    unsigned int src_i;

    dest_len = ft_strlen(dst);
    src_len = ft_strlen((char *)src);
    dest_i = dest_len;
    src_i = 0;
    if (dest_len >= dstsize)
        return (dstsize + src_len);
    while(src[src_i] && src_i < dstsize - dest_len - 1)
    {
        dst[dest_i + src_i] = src[src_i];
        src_i++;
    }
    dst[dest_i + src_i] = '\0';
    return (dest_len + src_len);
}

int main()
{
	char src[] = "marakuja";
	char dest[40] = "kaloryfer";
	int x = ft_strlen(dest);
	printf("len of dest: %i\n", x);
	printf("sizeof(dest): %lu\n", sizeof(dest));
    printf("len of src: %i\n", x);
	printf("sizeof(src): %lu\n", sizeof(src));


    printf("src: %s\ndest: %s\n", src, dest);
    size_t result = ft_strlcat(dest, src, sizeof(dest));

    printf("dest after: %s\n", dest);

    int i = 0;
    while (dest[i])
    {
        printf("%c\t%d\n", dest[i], dest[i]);
        i++;
    }
    printf("%c\t%d\n", dest[i], dest[i]);
}