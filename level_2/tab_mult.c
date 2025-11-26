#include <unistd.h>

long int	ft_atoi(char *str)
{
	long int	i;
	long int	result;
	long int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &(char){nb % 10 + '0'}, 1);
}

int	main(int argc, char **argv)
{
	long int	i;
	long int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 1;
	i = ft_atoi(argv[1]);
	while (j < 10)
	{
		ft_putnbr(j);
		write(1, " x ", 3);
		ft_putnbr(i);
		write(1, " = ", 3);
		ft_putnbr(j * i);
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
