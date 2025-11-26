#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	*p = (char *)s1;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return (p);
			j++;
		}
		i++;
		p++;
	}
	return (NULL);
}
