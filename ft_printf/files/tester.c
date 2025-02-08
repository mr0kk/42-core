#include "../libftprintf.h"

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

void test()
{
    // %d and %i
    ft_printf("intiger printing test:\n\n");
    int_test();

    // %u
    ft_printf("unsigned intiger printing test:\n\n");
    uint_test();

    // %x and %X
    // ft_printf("hex conversion testing:\n\n");
    // hex_test();
}

int main(void)
{
    //test();

    int x = 4;
    char *s = "ala ma kot";
    printf("%d %s\n", x, s);
}