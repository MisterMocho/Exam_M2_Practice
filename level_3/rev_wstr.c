#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{	
	int	i;
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = ft_strlen(argv[1]);
	j = i - 1;
	while (j >= 0)
	{
		while (j >= 0 && argv[1][j] != ' ' && argv[1][j] != '\t')
			j--;
		j++;
		write(1, &argv[1][j], i - j);
		if (j > 0)
			write(1, " ", 1);
		j -= 2;
		i = j + 1;
	}
	write(1, "\n", 1);
	return (0);
}
