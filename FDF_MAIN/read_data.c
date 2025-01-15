#include "mlx.h"
#include "mlx_int.h"
#include <stdlib.h>
#include <math.h>
#include "get_next_line.h"


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
static size_t	count_substr(char const *s, char c)
{
	size_t	numb;
	size_t	i;

	numb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			numb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (numb);
}

static int	free_ifmalloc_fails(char **array, size_t i)
{
	if (array[i] == NULL)
	{
		while (i-- > 0)
		{
			free (array[i]);
		}
		free (array);
		return (1);
	}
	return (0);
}

static const char	*skip_delimeters(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

static size_t	len_substr(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num_of_substr;
	char	**array;
	size_t	len;

	i = 0;
	num_of_substr = count_substr(s, c);
	array = malloc((num_of_substr + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s && i < num_of_substr)
	{
		s = skip_delimeters(s, c);
		len = len_substr(s, c);
		array[i] = malloc((len + 1) * sizeof(char));
		if (free_ifmalloc_fails(array, i) == 1)
			return (NULL);
		ft_strlcpy(array[i], s, len + 1);
		i++;
		s += len;
	}
	array[i] = NULL;
	return (array);
}

typedef struct s_data {
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int handle_close(void *param) {
	(void)param; // Avoid unused parameter warning
	exit(0); // Exit the program when "X" is clicked
}

// void	draw_line(void *mlx_ptr, void *win_ptr, int x, int y, int x1, int y1)
// {
// 	int dx = abs(x1 - x);    // Absolute difference in x
// 	int dy = abs(y1 - y);    // Absolute difference in y
// 	int sx = (x < x1) ? 1 : -1; // Step direction for x
// 	int sy = (y < y1) ? 1 : -1; // Step direction for y
// 	int err = dx - dy;       // Error term

// 	while (x != x1 || y != y1)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF); // Plot the pixel
// 		int e2 = 2 * err;      // Calculate the error term
// 		if (e2 > -dy)          // Adjust error and move in x-direction
// 		{
// 			err -= dy;
// 			x += sx;
// 		}
// 		if (e2 < dx)           // Adjust error and move in y-direction
// 		{
// 			err += dx;
// 			y += sy;
// 		}
// 	}
// }
int count_rows(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return -1;
	int row;
	row = 0;
	while (get_next_line(fd) != NULL)
	{
		row++;
	}
	return (row);
}
int count_col(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *line;
	char **content;
	int i;
	line = get_next_line(fd);
	content = ft_split(line, ' ');
	while (content[i])
		{
			free(content[i]);
			i++;
		}
		free(content);
		free(line);

	return (i);
}

int main(void)
{
    int col = count_col("basictest.fdf");
    int row = count_rows("basictest.fdf");

    printf("%i\n",col);
    printf("%i\n",row);

}