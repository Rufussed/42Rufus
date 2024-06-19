/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:56 by rlane             #+#    #+#             */
/*   Updated: 2024/06/19 13:46:47 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_window(t_data *data)
{
	int	win_w;
	int	win_h;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	win_w = data->map_width * SPRITE_SIZE;
	win_h = (data->map_height) * SPRITE_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_w, win_h, "So_Long");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error creating window\n");
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		handle_close, data);
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		data);
	load_tiles(data);
	draw_map_check_win(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	init_data_check_map(t_data *data)
{
	initialise_data(data);
	ft_printf("\n\nWelcome to \"So Long\"\n\n");
	ft_printf("Find all keys & exit\n\nGames Status:\n\n");
	if (!(read_next_map(data) && check_rectangular(data) && check_walls(data)
			&& check_chars_size(data) && check_player(data)
			&& check_game_objects(data)
			&& check_all_player_accessible_nodes(data)
			&& check_enemies(data)))
	{
		ft_printf("\nInvalid map !\n\n");
		free_data(data);
		return (0);
	}
	initialise_move_target(data);
	estimate_moves(data);
	print_report(data);
	return (1);
}

int	main(void)
{
	t_data	*data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->game_status = PLAYING;
	if (!init_data_check_map(data))
		return (1);
	if (open_window(data) == MLX_ERROR)
	{
		ft_printf("Error opening window\n");
		close_win_free_mlx(data);
		return (1);
	}
	close_win_free_mlx(data);
	free_data(data);
	return (0);
}
