unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	g;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		g = a;
	else if(b > a)
		g = b;
	while ((g % a != 0) || (g % b != 0))
		g++;
	return (g);
}
