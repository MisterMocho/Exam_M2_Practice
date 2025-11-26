#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int word;
    int nfc;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    word = 0;
    nfc = 0;
    while (argv[1][i])
    {
        if (!word)
        {
            while (argv[1][i] && (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
                i++;
            word = 1;
        }
        if (argv[1][i] && nfc == 1)
            write(1, " ", 1); 
        if (argv[1][i] && word == 1)
        {   
            while (argv[1][i] && (argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)))
            {   
                write(1, &argv[1][i], 1); 
                i++;
            }
            word = 0;
            nfc = 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}
