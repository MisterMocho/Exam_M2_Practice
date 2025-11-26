#include <unistd.h>

int	main (int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == ' ' || argv[j][i] == '\t')
				write(1, &argv[j][i], 1);
			else
			{
				if (i == 0 || argv[j][i - 1] == ' ' || argv[j][i - 1] == '\t')
				{
					if (argv[j][i] >='a' && argv[j][i] <= 'z')
						argv[j][i] -= 32;
				}
				else if(argv[j][i] >= 'A' && argv[j][i] <= 'Z')
					argv[j][i] += 32;
				write(1, &argv[j][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
