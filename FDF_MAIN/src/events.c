#include "../inlcude/fdf.h"

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == LEFT_KEY)
    {
        data->x_offset -= 40;  // Move map left
    }
    else if (keycode == RIGHT_KEY)
    {
        data->x_offset += 40;  // Move map right
    }
    else if (keycode == UP_KEY)
    {
        data->y_offset -= 40;  // Move map up
    }
    else if (keycode == DOWN_KEY)
    {
        data->y_offset += 40;  // Move map down
    }
    else if (keycode == ESC_KEY)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);  // Close window on ESC key
        exit(0);  // Exit the program
    }
	else if (keycode == KP_Add)
	{
		data->scale += 5;
	}
	else if (keycode == KP_Subtract)
	{
		data->scale -= 5;
	}

    // Redraw the map with the updated offsets (this does not affect the rotation)
    draw_map(data);

    return (0);
}


int handle_close(void *param) {
	(void)param; // Avoid unused parameter warning
	exit(0); // Exit the program when "X" is clicked
}