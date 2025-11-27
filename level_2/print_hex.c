#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

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

void	ft_putnbr_base(long int n,char *base)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, base);
	write(1, &base[n % 16], 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = ft_atoi(argv[1]);
	if (i >= 0)
		ft_putnbr_base((long)i, "0123456789abcdef");
	write(1, "\n", 1);
	return (0);
}
