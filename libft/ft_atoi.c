#include "libft.h"

int ft_atoi(const char *nptr)
{
    int result;
    int sign;

    sign = 1;
    result = 0;
    while(!ft_isprint(*nptr))
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    else if (!ft_isdigit(*nptr))
        return (result);
    else
    {
        result = *nptr - 48;
        nptr++;
    }
    while (*nptr && ft_isdigit(*nptr))
    {
        result = result * 10 + (*nptr - 48);
        nptr++;
    }
    return  (result * sign);
}

void tester(const char *str)
{
    if (atoi(str) == ft_atoi(str))
        printf("OK!\t\t%s: %d\n", str, ft_atoi(str));
    else
    {
        printf("FAIL\nstr: %s\natoi:%d\nft_atoi:%d\n", str, atoi(str), ft_atoi(str));
    }
    printf("--------------------------------------------\n");
}

int main(void)
{
    const char* tests[] = {
        "2",
        "11",
        "-32",
        "2147483647",
        "-2147483648",
        "1 2",
        "1234f532",
        "d",
        "23f",
        " -- 2",
        "-+-2"
        "-2",
        " ++2",
        "- 2",
        "-- 2",
        "+   4",
        "    ",
        " ",
        "\t\t",
        NULL
    };

    for (int i =0; tests[i] != NULL; i++)
        tester(tests[i]);
}
