unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	unsigned char	bit;
	int				i;

	i = 0;
	result = 0;
	while (i <= 7)
	{
		bit = (octet >> i) & 1;
		result = result << 1 | bit;
		i++;
	}
	return (result);
}