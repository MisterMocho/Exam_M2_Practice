#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(long int nb);

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int	result;
	int not_prime;

	if (argc != 2 || ft_atoi(argv[1]) <= 1)
	{
		write(1, "0", 1);
		return (0);
	}
	i = ft_atoi(argv[1]);
	result = 0;
	while (i > 1)
	{
		j = 2;
		not_prime = 0;
		while (j * j <= i)
		{
			if (i % j == 0)
			{
				not_prime = 1;
				break ;
			}
			j++;
		}
		if (not_prime == 0)
			result += i;
		i--;
	}
	ft_putnbr((long)result);
	write(1, "\n", 1);
	return(0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	result = 0;
	signal = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (signal * result);
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
