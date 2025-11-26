#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;
	int	size;

	i = 0;
	size = end - start;
	if (size < 0)
		size = -size;
	size += 1;
	range = malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	while (i < size)
	{	
		if (start <= end)
			range[i] = start++;
		else
			range[i] = start--;
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
