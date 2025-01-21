#include "../inlcude/fdf.h"
char	*ft_strcat(char *p, const char *src)
{
	size_t	len_p;
	size_t	len_src;
	size_t	i;

	if (p == NULL)
		return(NULL);
	len_p = ft_strlen(p);
	len_src = ft_strlen(src);
	i = 0;
	while (i < len_src)
	{
		p[len_p] = src[i];
		i++;
		len_p++;
	}
	p[len_p] = '\0';
	return (p);
}

void replace_nl(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
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


int update_frame(t_data *data)
{
    // Increment the rotation angle
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
    // Redraw the map
	
    draw_map(data);
	 usleep(16667);

    return (0);  // Returning 0 tells MiniLibX to continue the loop
}