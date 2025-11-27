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
	
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
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
    int digit;

    if (c >= '0' && c <= '9')
        digit = (c - '0');
    else if (c >= 'A' && c <= 'Z') // The exam asks up to and including base 16, this code accepts up to a base of 36.
        digit = (c - 'A' + 10);	   // If you feel the need to the exactly what the exam asks, replace 'Z' with 'F' and 'z' with 'f'.
    else if (c >= 'a' && c <= 'z') // That's it :D
        digit = (c - 'a' + 10);
    else
        return (-1);
	if (digit >= str_base)
		return (-1);
	return (digit);
}
