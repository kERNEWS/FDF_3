#include "../inlcude/fdf.h"

int main(int argc, char *argv[])
{
	t_data data;
	// t_map **grid;
	int width = 2500;
	int height = 2000;


	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, width, height, "Y");

	// Handle the "X" button event
	char *file = argv[argc - 1];
	char file_dir [100] = "test_maps/";
	ft_strcat(file_dir, file);
	data.col = count_col(file_dir);
	printf("COLS COUNTED");
	data.row = count_rows(file_dir);
	printf("ROWS COUNTED");
	data.x_offset = width/2;
    data.y_offset = height/2;
	data.scale = 15;

	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);


	data.grid = load_map(file_dir, data.col, data.row);
	printf("MAP LOADED");
	// draw_line(data.mlx_ptr, data.win_ptr, 0, 0, 500, 600);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	draw_map(&data);
	// Start the event loop
	mlx_loop(data.mlx_ptr);

	return (0);
}