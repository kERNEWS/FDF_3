#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/libft/libft.h"

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
} t_data;

#endif