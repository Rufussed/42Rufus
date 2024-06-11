/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:56 by rlane             #+#    #+#             */
/*   Updated: 2024/06/10 15:20:35 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tiles(t_data *data)
{
	int	img_width;
	int	img_height;

	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, 
			"assets/floor.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit.xpm", &img_width, &img_height);
	data->key = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/key.xpm", &img_width, &img_height);
	data->elf_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_up.xpm", &img_width, &img_height);
	data->elf_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_down.xpm", &img_width, &img_height);
	data->player = data->elf_down;
	data->elf_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_left.xpm", &img_width, &img_height);
	data->elf_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_right.xpm", &img_width, &img_height);
	if (data->floor == NULL || data->elf_left == NULL || data->exit == NULL
		|| data->elf_up == NULL || data->elf_down == NULL
		|| data->elf_right == NULL || data->key == NULL)
		exit(MLX_ERROR);
}

int	open_window(t_data *data)
{
	int	win_w;
	int	win_h;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	win_w = data->map_width * SPRITE_SIZE;
	win_h = data->map_height * SPRITE_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_w, win_h, "So_Long");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error creating window\n");
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, EVENT_CLOSE, 0, handle_close, NULL);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, 
		data);
	load_tiles(data);
	draw_map_check_win(data);
	mlx_loop(data->mlx_ptr);
	close_win_free_mlx(data);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	initialise_data(data);
	if (!read_map(data) || !check_walls(data) || !check_chars_size(data) || 
		!check_player(data) || !check_game_objects(data))
	{
		ft_printf("Error reading map\n");
		if (data->error)
			ft_printf("%s\n", data->error);
		free_data(data);
		return (1);
	}
	print_report(data);
	if (open_window(data) == MLX_ERROR)
	{
		ft_printf("Error opening window\n");
		close_win_free_mlx(data);
		return (1);
	}
	free_data(data);
	return (0);
}
