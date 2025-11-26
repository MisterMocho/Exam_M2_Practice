#include <unistd.h>

void	ft_putnbr(long n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &(char){(n - 1) + '0'}, 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 1)
		ft_putnbr((long)argc);
	write(1, "\n", 1);
	return (0);
}
