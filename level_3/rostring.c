#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	s;
	int	e;
	int	j;
	int fw;
	
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	j = 1;
	while (argv[j])
	{
		i = 0;
		fw = 1;
		while (argv[j][i])
		{
			if (is_space(argv[j][i]))
				i++;
			else if (!is_space(argv[j][i]))
			{
				if (fw == 1)
					s = i;
				while (argv[j][i] && !is_space(argv[j][i]))
				{
					if (fw == 0)
						write(1, &argv[j][i], 1);
					i++;	
				}
				if (fw == 0)
					write(1, " ", 1);
				if (fw == 1)
				{	
					e = i;
					fw = 0;
				}
			}
		}
		write(1, &argv[j][s], e - s);
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
