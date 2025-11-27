#include <unistd.h>

//this version i have made is fragile and it passes the exam, because in the subject they guarantee that,
//the tests they make, dont have trailing spaces before or after and have only 1 space between words.
//if the subject changes, this code won't work, you will have a different way in order to skip the spaces properly!

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
