/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:52 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 17:24:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"

// void	load_textures(t_data *data)
// {
// 	int	img_width = 200;
// 	int	img_height = 200;

// 	data->floor = mlx_xpm_file_to_image(data->mlx,
// 			"assets/floor.xpm", &img_width, &img_height);
// 	data->wall = mlx_xpm_file_to_image(data->mlx,
// 			"assets/wall.xpm", &img_width, &img_height);
	
// 		exit(MLX_ERROR);
// }

// Function to render the entire frame

int	render_frame(t_data *data)
{
	// Clear the previous frame
	mlx_clear_window(data->mlx, data->win);

	// Render the minimap (top-right corner)
	render_minimap(data);

	// Additional rendering can be added here

	return (0);
}


void init_data(t_data *data, char* map_path)
{
	data->map_path = map_path;
	parse_map(data);
	data->map = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->dir_x = 0.0;
	data->dir_y = 0.0;
	data->planeX = 0.0;
	data->planeY = 0.0;

	data->player_x = 500; // Starting position
	data->player_y = 500; // Starting position
	data->dir_x = 0.0;    // Facing up
	data->dir_y = -1.0;
	data->planeX = -0.66; // Perpendicular to dir_x/dir_y for FOV
	data->planeY = 0.0;
}



int	open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (data->win == NULL)
	{
		ft_printf("Error creating window\n");
		free(data->win);
		return (MLX_ERROR);
	}

	// Set up event hooks
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, handle_close, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);

	// Use a single loop hook for rendering
	mlx_loop_hook(data->mlx, render_frame, data);

	// Start the main loop
	mlx_loop(data->mlx);
	return (0);
}


int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (MLX_ERROR);
	init_data(data, argv[1]);
	if (open_window(data) == MLX_ERROR)
		return (MLX_ERROR);
	free(data);
	return (0);
}