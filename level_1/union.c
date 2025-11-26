#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int found[256] = {};
	
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 1;
	while (argv[j])
	{
		if (!found[(unsigned char)argv[j][i]])
		{
			write(1, &argv[j][i], 1);
			found[(unsigned char)argv[j][i]] = 1;
		}
		i++;
		if (argv[j][i] == '\0')
		{
			j++;
			i = 0;
		}
	}
	write(1, "\n", 1);
	return (0);
}
