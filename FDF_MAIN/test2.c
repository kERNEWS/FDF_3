#include "inlcude/fdf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
unsigned int ft_atoi_base(const char *str, int base)
{
    unsigned int result = 0;

    // Skip optional "0x" or "0X" for base 16
    if (base == 16 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        str += 2;

    while (*str && (ft_isdigit(*str) || (*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f')))
    {
        result *= base;
        if (ft_isdigit(*str))
            result += *str - '0';
        else if (*str >= 'A' && *str <= 'F')
            result += *str - 'A' + 10;
        else if (*str >= 'a' && *str <= 'f')
            result += *str - 'a' + 10;
        str++;
    }
    return result;
}

int main()
{
    char *c = ",0xFFFFDD";
    unsigned int d = ft_atoi_base(c + 1, 16);
    printf("%i", d);
}