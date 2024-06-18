/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:53 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 15:49:43 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialise_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
	data->elf_up = NULL;
	data->elf_down = NULL;
	data->elf_left = NULL;
	data->elf_right = NULL;
	data->elf_dead = NULL;
	data->player = NULL;
	data->key = NULL;
	data->map = NULL;
	data->black = NULL;
	data->map_path = MAP1;
	data->map_width = 0;
	data->map_height = 0;
	data->game_status = PLAYING;
	data->direction = NONE;
	data->moves = 0;
	data->est_moves = 0;
	data->key_count = 0;
	data->floor_count = 0;
	data->exit_count = 0;
	data->accessible_nodes = 0;
	init_enemy_data(data);
}

void	init_enemy_data(t_data *data)
{
	int	i;

	data->enemy_count = 0;
	data->enemy_up = NULL;
	data->enemy_down = NULL;
	data->enemy_left = NULL;
	data->enemy_right = NULL;
	data->win = NULL;
	data->lose = NULL;
	data->green_steps = NULL;
	data->red_steps = NULL;
	data->enemies = malloc(MAX_ENEMIES * sizeof(t_enemy));
	i = 0;
	while (i < MAX_ENEMIES)
	{
		data->enemies[i].x = 0;
		data->enemies[i].y = 0;
		data->enemies[i].emov_x = 0;
		data->enemies[i].emov_y = 0;
		data->x[i] = 0;
		data->y[i] = 0;
		data->enemies[i].enemy = NULL;
		data->enemies[i].direction = NONE;
		i++;
	}
}

void	initialise_move_target(t_data *data)
{
	data->move_x = data->player_x;
	data->move_y = data->player_y;
}
