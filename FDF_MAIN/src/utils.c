#include "../inlcude/fdf.h"

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

int update_frame(t_data *data)
{
    // Increment the rotation angle
    data->rotation_angle += 0.00;  // Adjust the speed of rotation
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