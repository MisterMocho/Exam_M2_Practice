#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	size;
	int *range;
	int	step;

	i = 0;
	size = end - start;
	if (size < 0)
		size = -size;
	size++;
	range = malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	step = (end > start) ? -1 : 1;
	while (i < size)
	{
		range[i] = end;
		end += step;
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
	arr = ft_rrange(s, e);
	while (i < size)
	{
		printf("%i ,", arr[i]);
		i++;
	}
	return (0);
}
*/