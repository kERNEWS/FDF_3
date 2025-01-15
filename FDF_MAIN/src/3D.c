#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include <math.h>
#include "../lib/libft/get_next_line.h"
#include "../lib/libft/libft.h"
#include <unistd.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define UP_KEY 65362
#define DOWN_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define ESC_KEY 65307

typedef struct s_map
{
	int height;
	int color;

}t_map;

typedef struct s_data {
	void *mlx_ptr;
	void *win_ptr;
	t_map **grid;
	int row;
	int col;
	int x_offset;
	int y_offset;
	float rotation_angle;
} t_data;

void draw_map(t_data *data);

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == LEFT_KEY)
    {
        data->x_offset += 20;  // Move map left
    }
    else if (keycode == RIGHT_KEY)
    {
        data->x_offset -= 20;  // Move map right
    }
    else if (keycode == UP_KEY)
    {
        data->y_offset += 20;  // Move map up
    }
    else if (keycode == DOWN_KEY)
    {
        data->y_offset -= 20;  // Move map down
    }
    else if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);  // Close window on ESC key
        exit(0);  // Exit the program
    }

    // Redraw the map with the updated offsets (this does not affect the rotation)
    draw_map(data);

    return (0);
}


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

int handle_close(void *param) {
	(void)param; // Avoid unused parameter warning
	exit(0); // Exit the program when "X" is clicked
}


void	draw_line(void *mlx_ptr, void *win_ptr, int x, int y, int x1, int y1)
{
	int dx = abs(x1 - x);    // Absolute difference in x
	int dy = abs(y1 - y);    // Absolute difference in y
	int sx = (x < x1) ? 1 : -1; // Step direction for x
	int sy = (y < y1) ? 1 : -1; // Step direction for y
	int err = dx - dy;       // Error term

	while (x != x1 || y != y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF); // Plot the pixel
		int e2 = 2 * err;      // Calculate the error term
		if (e2 > -dy)          // Adjust error and move in x-direction
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)           // Adjust error and move in y-direction
		{
			err += dx;
			y += sy;
		}
	}
}
int count_rows(char *file_name)
{
	char *line;
	int fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return -1;
	int row;
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		row++;
	}
	close(fd);
	return (row);
}
int count_col(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
    if (fd < 0)
	{
        return (-1);
	}
	char *line;
	char **content;
	int i;
    i = 0;
	line = get_next_line(fd);
	content = ft_split(line, ' ');
	while (content[i])
		{
			free(content[i]);
			i++;
		}
		free(content);
		free(line);
	while(get_next_line(fd) != NULL)
	close(fd);
	return (i);
}
static int	is_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
	{
		return (1);
	}
	return (0);
}

static int	check_sign(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	while (is_space(nptr[i]))
	{
		i++;
	}
	sign = check_sign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}

static char	*ft_strcat(char *p, const char *src)
{
	size_t	len_p;
	size_t	len_src;
	size_t	i;

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


t_map **alloc_grid(int row, int col)
{
	t_map **grid;
	int i;

	i = 0;
	if ((grid = malloc(row * sizeof(t_map *))) == NULL)
		return (NULL);
	while (i < row)
	{
		if ((grid [i] = malloc(col * sizeof(t_map))) == NULL)
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return(NULL);
		}
		i++;
	}
	return (grid);
}
void convert_and_store(t_map **grid, int row, int col, char **content)
{
	int i;
	int k;
	int t;

	i = 0;
	t = 0;
	while (i < row)
	{
		k = 0;
		while(k < col)
		{
			if (t >= row * col)
				return;
			grid[i][k].height = ft_atoi(content[t++]);
			k++;
		}
		i++;
	}
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



t_map **load_map(char *file_name, int col, int row)
{
	char **content;
	char *s;
	char *str;
	t_map **grid;

	int fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = malloc((col * row) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while(1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break;
		str = ft_strcat(str, s);
	}
	replace_nl(str);
	if (((content) = ft_split(str, ' ')) == NULL)
		return(NULL);
	if ((grid = alloc_grid(row, col)) == NULL)
		return (NULL);
	convert_and_store(grid, row, col, content);
	return (grid);

}

void project_isometric(float x, float y, float z, int *x_proj, int *y_proj, int scale)
{
    float angle_x = 45 * M_PI / 180;  // 45° in radians
    float angle_y = 10 * M_PI / 180;  // 30° in radians

    *x_proj = (x - y) * cos(angle_x) * scale;
    *y_proj = (x + y) * sin(angle_y) * scale - z * scale;
}

#include <math.h>

void rotate_point(float *x, float *y, float *z, float pivot_x, float pivot_y, float pivot_z, float angle_x, float angle_y, float angle_z)
{
    // Step 1: Translate point relative to pivot
    *x -= pivot_x;
    *y -= pivot_y;
    *z -= pivot_z;

    float temp_x, temp_y, temp_z;

    // Step 2: Rotation around X-axis
    temp_y = *y * cos(angle_x) - *z * sin(angle_x);
    temp_z = *y * sin(angle_x) + *z * cos(angle_x);
    *y = temp_y;
    *z = temp_z;

    // Rotation around Y-axis
    temp_x = *x * cos(angle_y) + *z * sin(angle_y);
    temp_z = -*x * sin(angle_y) + *z * cos(angle_y);
    *x = temp_x;
    *z = temp_z;

    // Rotation around Z-axis
    temp_x = *x * cos(angle_z) - *y * sin(angle_z);
    temp_y = *x * sin(angle_z) + *y * cos(angle_z);
    *x = temp_x;
    *y = temp_y;

    // Step 3: Translate point back
    *x += pivot_x;
    *y += pivot_y;
    *z += pivot_z;
}



void draw_map(t_data *data)
{
    int i, k;
    int projx, projy, projx2, projy2;
    int scale = 10;


    int x_offset = data->x_offset;
    int y_offset = data->y_offset;
    t_map **grid = data->grid;

    // Calculate the pivot point (center of the map)
    float pivot_x = (data->row - 1) / 2.0;
    float pivot_y = (data->col - 1) / 2.0;
    float pivot_z = 0.0;  // Set this to a meaningful value if needed

    for (i = 0; i < data->row; i++)
    {
        for (k = 0; k < data->col; k++)
        {
            float x = i;
            float y = k;
            float z = grid[i][k].height;

            // Rotate around the pivot point
            rotate_point(&x, &y, &z, pivot_x, pivot_y, pivot_z, 0, 0, data->rotation_angle);

            // Project the rotated point
            project_isometric(x, y, z, &projx, &projy, scale);
            projx += x_offset;
            projy += y_offset;

            // Draw horizontal and vertical lines
            if (k + 1 < data->col)
            {
                float next_x = i;
                float next_y = k + 1;
                float next_z = grid[i][k + 1].height;

                rotate_point(&next_x, &next_y, &next_z, pivot_x, pivot_y, pivot_z, 0, 0, data->rotation_angle);
                project_isometric(next_x, next_y, next_z, &projx2, &projy2, scale);
                projx2 += x_offset;
                projy2 += y_offset;

                draw_line(data->mlx_ptr, data->win_ptr, projx, projy, projx2, projy2);
            }

            if (i + 1 < data->row)
            {
                float next_x = i + 1;
                float next_y = k;
                float next_z = grid[i + 1][k].height;

                rotate_point(&next_x, &next_y, &next_z, pivot_x, pivot_y, pivot_z, 0, 0, data->rotation_angle);
                project_isometric(next_x, next_y, next_z, &projx2, &projy2, scale);
                projx2 += x_offset;
                projy2 += y_offset;

                draw_line(data->mlx_ptr, data->win_ptr, projx, projy, projx2, projy2);
            }
        }
    }
}


int update_frame(t_data *data)
{
    // Increment the rotation angle
    data->rotation_angle += 0.01;  // Adjust the speed of rotation
    if (data->rotation_angle >= 360.0)
	{
    	data->rotation_angle = 0.0;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
    // Redraw the map
	
    draw_map(data);
	 usleep(16667);

    return (0);  // Returning 0 tells MiniLibX to continue the loop
}



int main() {
	t_data data;
	// t_map **grid;
	int width = 1080;
	int height = 1500;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, width, height, "Y");

	// Handle the "X" button event
	char *file_name = "test_maps/mars.fdf";
	data.col = count_col(file_name);
	data.row = count_rows(file_name);
	data.x_offset = width / 2;
    data.y_offset = height / 2;
	data.rotation_angle = 0.1;

	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);


	data.grid = load_map(file_name, data.col, data.row);
	// draw_line(data.mlx_ptr, data.win_ptr, 0, 0, 500, 600);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	draw_map(&data);
	mlx_loop_hook(data.mlx_ptr, update_frame, &data);
	// Start the event loop
	mlx_loop(data.mlx_ptr);

	return (0);
}