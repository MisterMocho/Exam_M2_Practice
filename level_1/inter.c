#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	found[256] = {};

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{	
			if (argv[1][i] == argv[2][j] && !found[(int)argv[1][i]])
			{
				found[(int)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
