#include <unistd.h>

void	ft_putnbr(long n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &(char){(n % 10) + '0'}, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc >= 1)
		ft_putnbr((long)argc - 1);
	write(1, "\n", 1);
	return (0);
}
