#include "libftprintf.h"

/*
    %c - character 
    %s - string
    %f - float 
    %lf - double 
    %d - intiger 

    %.1 - deciman precision
    %1 - minimmum fild width
    %- - left align

    va_list args;  
    va_start(args, count);
    va_arg(args, int);
    va_end(args); 
*/

int sum(int count, ...)
{
    va_list args;   // Declare a variable to hold the arguments
    va_start(args, count);

    int result = 0;
    int i = 0;
    while (i < count)
    {
        result += va_arg(args, int);
        i++;
    }
    va_end(args);

    return (result);
}

int main(void)
{
    printf("sum: %d\n", sum(3, 4, 5, 1));

    printf("%c\n", ft_tolower('A'));
}