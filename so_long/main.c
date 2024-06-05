#include "so_long.h"

void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		mlx_put_pixel(img, x0, y0, color); // Draw pixel

		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

int32_t main(void)
{
	mlx_t	*mlx;
	mlx_image_t *img;

	// Initialize the MLX42 library and create a window
	mlx = mlx_init(800, 600, "Draw Line", false);
	if (!mlx)
	{
		fprintf(stderr, "Failed to initialize MLX42\n");
		return EXIT_FAILURE;
	}

	// Create an image
	img = mlx_new_image(mlx, 800, 600);
	if (!img)
	{
		fprintf(stderr, "Failed to create image\n");
		mlx_terminate(mlx);
		return EXIT_FAILURE;
	}

	// Draw a line from (100, 100) to (700, 500)
	draw_line(img, 100, 100, 700, 500, 0xFFFFFFFF);

	// Display the image in the window
	mlx_image_to_window(mlx, img, 0, 0);

	// Enter the MLX42 event loop
	mlx_loop(mlx);

	// Cleanup
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);

	return EXIT_SUCCESS;
}
