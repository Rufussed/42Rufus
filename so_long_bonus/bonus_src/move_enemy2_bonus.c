/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:57:40 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 13:25:53 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_enemy_enemy_collision(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;

	x = data->enemies[i].emov_x;
	y = data->enemies[i].emov_y;
	j = 0;
	while (j < data->enemy_count)
	{
		if (j == i)
			j++;
		if ((data->enemies[j].x == x && data->enemies[j].y == y)
			|| (data->enemies[j].emov_x == x && data->enemies[j].emov_y == y))
		{
			data->enemies[i].emov_x = data->enemies[i].x;
			data->enemies[i].emov_y = data->enemies[i].y;
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_move_enemy(t_data *data, int i)
{
	int	x;
	int	y;

	if (!check_enemy_enemy_collision(data, i))
		return (0);
	x = data->enemies[i].emov_x;
	y = data->enemies[i].emov_y;
	if (data->map[y][x] == '1' || data->map[y][x] == 'X'
		|| (data->map[y][x] == 'C' || data->map[y][x] == 'E'))
	{
		data->enemies[i].emov_x = data->enemies[i].x;
		data->enemies[i].emov_y = data->enemies[i].y;
		return (0);
	}
	return (1);
}

int	set_move_enemy_horizontal(t_data *data, int i)
{
	if (data->player_x < data->enemies[i].x)
	{
		data->enemies[i].emov_x = data->enemies[i].x - 1;
		data->enemies[i].emov_y = data->enemies[i].y;
		data->enemies[i].enemy = data->enemy_left;
		data->enemies[i].direction = LEFT;
		if (check_move_enemy(data, i))
			return (1);
	}
	if (data->player_x > data->enemies[i].x)
	{
		data->enemies[i].emov_x = data->enemies[i].x + 1;
		data->enemies[i].emov_y = data->enemies[i].y;
		data->enemies[i].enemy = data->enemy_right;
		data->enemies[i].direction = RIGHT;
		if (check_move_enemy(data, i))
			return (1);
	}
	return (0);
}

int	set_move_enemy(t_data *data, int i)
{
	if (set_move_enemy_horizontal(data, i))
		return (1);
	if (data->player_y < data->enemies[i].y)
	{
		data->enemies[i].emov_x = data->enemies[i].x;
		data->enemies[i].emov_y = data->enemies[i].y - 1;
		data->enemies[i].enemy = data->enemy_up;
		data->enemies[i].direction = UP;
		if (check_move_enemy(data, i))
			return (1);
	}
	if (data->player_y > data->enemies[i].y)
	{
		data->enemies[i].emov_x = data->enemies[i].x;
		data->enemies[i].emov_y = data->enemies[i].y + 1;
		data->enemies[i].enemy = data->enemy_down;
		data->enemies[i].direction = DOWN;
		if (check_move_enemy(data, i))
			return (1);
	}
	return (0);
}
