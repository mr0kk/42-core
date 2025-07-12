#include "../include/so_long.h"

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
    return ((trgb >>16) & 0xFF);
}

int get_g(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
    return (trgb & 0xFF);
}

int add_shade(double shade, int color)
{
    int t = (color >> 24) & 0xFF;
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    r = (int)(r * shade);
    g = (int)(g * shade);
    b = (int)(b * shade);

    return (t << 24 | g << 16 | g << 8 | b);
}

int get_opposite(int color) // not working properly
{
    int t = (color >> 24) & 0xFF;
    int r = ~((color >> 16) & 0xFF);
    int g = ~((color >> 8) & 0xFF);
    int b = ~(color & 0xFF);

    return (t << 24 | g << 16 | g << 8 | b);
}

int main()
{
    unsigned int    color = 0xFFFFFFFF;

    printf("color:\n%#X\n", color);
    printf("t:\t%#X\t=\t%d\n", get_t(color), get_t(color));
    printf("red:\t%#X\t=\t%d\n", get_r(color), get_r(color));
    printf("green:\t%#X\t=\t%d\n", get_g(color), get_g(color));
    printf("blue:\t%#X\t=\t%d\n\n", get_b(color), get_b(color));

    unsigned int shaded = add_shade(0.5, color);
    printf("add_shade:\n%#X\n", shaded);
    printf("t:\t%#X\t=\t%d\n", get_t(shaded), get_t(shaded));
    printf("red:\t%#X\t=\t%d\n", get_r(shaded), get_r(shaded));
    printf("green:\t%#X\t=\t%d\n", get_g(shaded), get_g(shaded));
    printf("blue:\t%#X\t=\t%d\n\n", get_b(shaded), get_b(shaded));

    unsigned int opposite = get_opposite(color);
    printf("opposite:\n%#X\n", opposite);
    printf("t:\t%#X\t=\t%d\n", get_t(opposite), get_t(opposite));
    printf("red:\t%#X\t=\t%d\n", get_r(opposite), get_r(opposite));
    printf("green:\t%#X\t=\t%d\n", get_g(opposite), get_g(opposite));
    printf("blue:\t%#X\t=\t%d\n", get_b(opposite), get_b(opposite));
}
