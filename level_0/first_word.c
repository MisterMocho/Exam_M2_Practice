#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 0;
	if (argc != 2)
		return (write(1, "\n", 1), 0);
	while (argv[1][i])
	{
		flag = 0;
		while (flag == 0 && argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] >= 9 && argv[1][i] <= 13)
				i++;
			else
				flag = 1;
		}
		while (flag == 1 && argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] >= 9 && argv[1][i] <= 13)
				break ;
			write(1, &argv[1][i], 1);
			i++;
		}
		break ;
	}
	write(1, "\n", 1);
	return (0);
}