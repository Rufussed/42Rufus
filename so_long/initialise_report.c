/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_report.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:53 by rlane             #+#    #+#             */
/*   Updated: 2024/06/13 12:41:06 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise_data(t_data *data)
{
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->move_x = 0;
	data->move_y = 0;
	data->moves = 0;
	data->est_moves = 0;
	data->key_count = 0;
	data->floor_count = 0;
	data->exit_count = 0;
	data->accessible_nodes = -1;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
	data->elf_up = NULL;
	data->elf_down = NULL;
	data->elf_left = NULL;
	data->elf_right = NULL;
	data->player = NULL;
	data->key = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

int	error_set(int error)
{
	if (error == NOT_RECTANGLE_ERROR)
		ft_printf("%s\n", "\033[31mMap is not rectangular");
	if (error == BAD_WALLS_ERROR)
		ft_printf("%s\n", "\033[31mMap has bad walls");
	if (error == COLLECTIBLES_ERROR)
		ft_printf("%s\n", "\033[31mMap has no collectibles");
	if (error == EXITS_ERROR)
		ft_printf("%s\n", "\033[31mMap has exit count is not 1");
	if (error == PLAYER_ERROR)
		ft_printf("%s\n", "\033[31mMap player count is not 1");
	if (error == INVALID_CHAR_ERROR)
		ft_printf("%s\n", "\033[31mMap has invalid characters");
	if (error == MAP_OVERSIZE_ERROR)
		ft_printf("%s\n", "\033[31mMap is too big");
	if (error == MAP_UNDERSIZE_ERROR)
		ft_printf("%s\n", "\033[31mMap is too small");
	if (error == NO_VALID_PATH_ERROR)
		ft_printf("%s\n", "\033[31mUnsolvable Map");
	return (0);
}

void	initialise_move_target(t_data *data)
{
	data->move_x = data->player_x;
	data->move_y = data->player_y;
}

void	estimate_moves(t_data *data)
{
	int		i;

	i = data->key_count;
	data->est_moves = data->map_width + data->map_height;
	while (i > 0)
	{
		data->est_moves += i / (data->key_count)
			* (data->map_width * data->map_height) * 0.15;
		i--;
	}
}

void	print_report(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("\nMap width = %d\n", data->map_width);
	ft_printf("Map height = %d\n\n", data->map_height);
	ft_printf("Player x = %d\n", data->player_x);
	ft_printf("Player y = %d\n\n", data->player_y);
	ft_printf("Estimated Moves = %d\n\n", data->est_moves);
}
