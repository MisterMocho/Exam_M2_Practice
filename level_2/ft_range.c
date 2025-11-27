#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;
	int	size;
	int	step;
	
	i = 0;
	size = end - start;
	if (size < 0)
		size = -size;
	size += 1;
	range = malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	if (start <= end)
		step = 1;
	else
		step = -1;
	while (i < size)
	{	
		range[i] = start;
		start = start + step;
		i++;
	}
	return (range);
}
/*
int	main(void)
{
	int	s = 3;
	int e = -2;
	int size = e - s;
	int	*arr;
	int	i;

	if (size < 0)
		size = -size;
	size += 1;
	i = 0;
	arr = ft_range(s, e);
	while (i < size)
	{
		printf("%i ,", arr[i]);
		i++;
	}
	return (0);
}
*/
