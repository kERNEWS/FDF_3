#include "../inlcude/fdf.h"
void	draw_line(void *mlx_ptr, void *win_ptr, int x, int y, int x1, int y1);

void project_isometric(float x, float y, float z, int *x_proj, int *y_proj, int scale)
{
    float angle_x = 40 * M_PI / 180;  // 45° in radians
    float angle_y = 25 * M_PI / 180;  // 30° in radians

    *x_proj = (x + y) * cos(angle_x) * scale;
    *y_proj = (x - y) * sin(angle_y) * scale - z * scale * 0.3;
}


void draw_map(t_data *data)
{
    int i, k;
    int projx, projy, projx2, projy2;
	int scale = data->scale;


    int x_offset = data->x_offset;
    int y_offset = data->y_offset;
    t_map **grid = data->grid;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);

    for (i = 0; i < data->row; i++)
    {
        for (k = 0; k < data->col; k++)
        {
            float x = i;
            float y = k;
            float z = grid[i][k].height;


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

                project_isometric(next_x, next_y, next_z, &projx2, &projy2, scale);
                projx2 += x_offset;
                projy2 += y_offset;

                draw_line(data->mlx_ptr, data->win_ptr, projx, projy, projx2, projy2);
            }
        }
    }
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
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xAAADDD); // Plot the pixel
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