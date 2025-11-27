#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i] && is_space(argv[1][i]))
        i++;
    while (argv[1][i])
    {
        while (argv[1][i] && !is_space(argv[1][i]))
        {
            write(1, &argv[1][i], 1);
            i++;
        }
        while (argv[1][i] && is_space(argv[1][i]))
            i++;
        if (argv[1][i])
            write(1, "   ", 3);
    }
    write(1, "\n", 1);
    return (0);
}
