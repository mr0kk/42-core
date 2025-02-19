
#include "get_next_line.h"

char *test(char *s)
{
    int len = strlen(s);
    int i = 0;


    char *res = (char *)malloc((len + 1) * sizeof(char));
    if (!res)
    {
        free(s);
        return (NULL);
    }

    while (i < len)
    {
        res[i] = s[i];
        i++;
    }
    res[i] = '\0';
    free(s);
    return (res);
}

char *testowy()
{
    char *res;

    res = (char *)malloc(30);
    if (!res)
    {
        return (NULL);
    }
    res[0] = '1';
    res[1] = '2';
    res[2] = '3';
    res[3] = '4';
    res[4] = '5';
    res[5] = '6';
    res[6] = '\0';
    
    return(test(res));
}

int main()
{
    char * res = testowy();
    printf("%s\n", res);
    free(res);
}