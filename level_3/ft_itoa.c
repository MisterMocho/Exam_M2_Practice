#include <stdlib.h>

int	ft_intlen(long int i)
{
	int len;

	len = 0;
	if (i <= 0)
		len = 1;
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	long int		i;
	unsigned int	len;

	i = nbr;
	len = ft_intlen(i);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (i == 0)
		str[0] = '0';
	else if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	while (i > 0)
	{
		len--;
		str[len] = (i % 10) + '0';
		i /= 10;
	}
	return (str);
}
