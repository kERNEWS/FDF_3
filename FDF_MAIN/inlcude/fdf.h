#ifndef FDF_H
# define FDF_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include <math.h>
#include "../lib/libft/get_next_line.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <errno.h>
#include "../inlcude/fdf.h"

#define M_PI 3.14159265358979323846

#define UP_KEY 65362
#define DOWN_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define ESC_KEY 65307
#define KP_Add        0xFFAB  // Keypad Plus
#define KP_Subtract  0xffad  // Keypad Subtract


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
	int scale;
} t_data;

int handle_keypress(int keycode, t_data *data);

int handle_close(void *param);
int update_frame(t_data *data);
int count_rows(char *file_name);
int count_col(char *file_name);
t_map **load_map(char *file_name, int col, int row);
void convert_and_store(t_map **grid, int row, int col, char **content);
void draw_map(t_data *data);
void replace_nl(char *str);
int update_frame(t_data *data);




#endif