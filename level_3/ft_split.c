#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_wordcount(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{	
			n++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	return (n);
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	int wc;
	int start;
	char	*ss;
	char	**s;

	if (!str)
		return (NULL);
	wc = ft_wordcount(str);
	s = malloc((wc + 1) * sizeof(char *));
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		k = 0;
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		ss = malloc((i - start) + 1);
		if (!ss)
		{
			while (j > 0)
				free(s[--j]);
			free(s);
			return(NULL);
		}
		while (start < i)
		{
			ss[k] = str[start];
			k++;
			start++;
		}
		ss[k] = '\0';
		s[j] = ss;
		j++;
	}
	s[j] = NULL;
	return (s);
}

/*
int main(int argc, char **argv)
{
    char **words;
    int i;

    if (argc != 2)
    {
        printf("Usage: %s \"string to split\"\n", argv[0]);
        return 1;
    }

    words = ft_split(argv[1]);
    if (!words)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    i = 0;
    while (words[i])
    {
        printf("Word %d: \"%s\"\n", i, words[i]);
        free(words[i]); // free each allocated word
        i++;
    }

    free(words); // free the array of pointers
    return 0;
}
*/