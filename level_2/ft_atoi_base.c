#include <unistd.h>
/*#include <stdio.h>*/

int ft_get_digit(char c, int str_base);
int ft_atoi_base(const char *str, int str_base);
/*
int main(void)
{
	printf("%d", ft_atoi_base("5F10a", 16));
	return (0);
}
*/

int ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;
    int i;
    int digit;

    result = 0;
    i = 0;
    sign = 1;

    if (str[i] && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ((digit = ft_get_digit(str[i], str_base)) >= 0)
    {
        result = result * str_base + digit;
        i++;
    }
    return (result * sign);
}

int ft_get_digit(char c, int str_base)
{
    int max_digit;

    if (str_base <= 10)
        max_digit = str_base - 1 + '0';
    else
        max_digit = str_base - 11 + 'a';
    if (c >= '0' && c <= '9' && c <= max_digit)
        return(c - '0');
    else if (c >= 'A' && c <= 'F' && c <= max_digit - 32)
        return (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f' && c <= max_digit)
        return (c - 'a' + 10);
    else
        return (-1);
}
