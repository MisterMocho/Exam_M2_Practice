int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int 			j;

	if (len == 0)
		return (0);
	i = 0;
	j = tab[0];
	while (i < len)
	{
		if (tab[i] > j)
			j = tab[i];
		i++;
	}
	return (j);
}