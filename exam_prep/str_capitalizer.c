#include <unistd.h>

int is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void capitalize_words(char *str)
{
    int i = 0;
    int new_word = 1;  // Flag to track start of new word

    while (str[i])
    {
        if (is_letter(str[i]))
        {
            if (new_word)
            {
                // Capitalize first letter of word
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] -= 32;
                new_word = 0;
            }
            else
            {
                // Lowercase other letters
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] += 32;
            }
        }
        else
        {
            // Non-letter character marks new word
            new_word = 1;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        capitalize_words(argv[i]);
        int j = 0;
        while (argv[i][j])
            write(1, &argv[i][j++], 1);
        write(1, "\n", 1);
    }

    return 0;
}