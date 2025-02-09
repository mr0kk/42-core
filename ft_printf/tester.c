#include "ft_printf.h"

void int_test()
{
    int res;
    int min = INT_MIN;
    int max = INT_MAX;

    res = printf("%d", 0);
    printf("\tlen = %d\tprintf\n", res);

    res = ft_printf("%d", 0);
    printf("\tlen = %d\tft_printf\n\n", res);

    res = printf("%d", min);
    printf("\tlen = %d\tprintf\n", res);

    res = ft_printf("%d", min);
    printf("\tlen = %d\tft_printf\n\n", res);
    
    res = printf("%d", max);
    printf("\tlen = %d\tprintf\n", res);

    res = ft_printf("%i", max);
    printf("\tlen = %d\tft_printf\n\n", res);
}
void uint_test()
{
    int umax = UINT_MAX;
    int res;

    res = printf("%d", 0);
    printf("\tlen = %d\tprintf\n", res);

    res = ft_printf("%d", 0);
    printf("\tlen = %d\tft_printf\n\n", res);

    res = printf("%u", umax);
    printf("\tlen = %d\tprintf\n", res);

    res = ft_printf("%u", umax);
    printf("\tlen = %d\tft_printf\n\n", res);
}

void hex_test()
{
    unsigned int x;
    int len;

    ft_printf("if x:\n");
    x = 125;
    ft_printf("int: %u\n", x);
    len = printf("%x", x);
    printf("\tlen = %d\t\tprintf\n", len);
    len = ft_printf("%x", x);
    ft_printf("\tlen = %d\t\tft_printf\n\n", len);

    x = UINT_MAX;
    ft_printf("int: %u\n", x);
    len = printf("%x", x);
    printf("\tlen = %d\t\tprintf\n", len);
    len = ft_printf("%x", x);
    ft_printf("\tlen = %d\t\tft_printf\n\n", len);

    x = 0;
    ft_printf("int: %u\n", x);
    len = printf("%x", x);
    printf("\tlen = %d\t\tprintf\n", len);
    len = ft_printf("%x", x);
    ft_printf("\tlen = %d\t\tft_printf\n\n", len);

    x = -40;
    ft_printf("int: %u\n", x);
    len = printf("%x", x);
    printf("\tlen = %d\t\tprintf\n", len);
    len = ft_printf("%x", x);
    ft_printf("\tlen = %d\t\tft_printf\n\n", len);

    ft_printf("if X:\n");
    x = UINT_MAX;
    ft_printf("int: %u\n", x);
    len = printf("%X", x);
    printf("\tlen = %d\t\tprintf\n", len);
    len = ft_printf("%X", x);
    ft_printf("\tlen = %d\t\tft_printf\n\n", len);
}

void s_test()
{
    char *s = NULL;
    int res;

    res = printf(" NULL %s NULL ", s);
    printf("\tlen: %d\t\t:printf\n", res);
    res = ft_printf(" NULL %s NULL ", s);
    printf("\tlen: %d\t\t:ft_printf\n\n\n", res);

    res = printf("%s", s);
    printf("\tlen: %d\t\t:printf\n", res);
    res = ft_printf("%s", s);
    printf("\tlen: %d\t\t:ft_printf\n", res);
}

void    p_test()
{
    int x = 5;
    int *p = &x;
    int res;

    res = printf("%p", p);
    printf("\t\tlen: %d\t:printf\n",res);
    res = ft_printf("%p", p);
    printf("\t\tlen: %d\t:ft_printf\n\n\n", res);

    p = NULL;
    res = printf("%p", p);
    printf("\t\tlen: %d\t:printf\n", res);
    res = ft_printf("%p", p);
    printf("\t\tlen: %d\t:ft_printf\n\n\n", res);
}

void test()
{
    // // %s
    // ft_printf("string test:\n\n");
    // s_test();

    // // %p
    // ft_printf("pointer test:\n\n");
    // p_test();

    // // %d and %i
    // ft_printf("intiger printing test:\n\n");
    // int_test();

    // // %u
    // ft_printf("unsigned intiger printing test:\n\n");
    // uint_test();

    // // %x and %X
    // ft_printf("hex conversion testing:\n\n");
    // hex_test();
}

int main(void)
{
    test();
}