/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:57:40 by rlane             #+#    #+#             */
/*   Updated: 2024/06/14 09:30:02 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_move(t_data *data)
{
	if (data->map[data->move_y][data->move_x] == '1' 
		|| (data->map[data->move_y][data->move_x] 
			== 'E' && data->key_count > 0))
	{
		data->move_x = data->player_x;
		data->move_y = data->player_y;
		return (0);
	}
	return (1);
}

void	move_player(t_data *data)
{
	if (check_move(data))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_x = data->move_x;
		data->player_y = data->move_y;
		data->moves++;
	}
}

int	check_move_enemy(t_data *data, int i)
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
	if (data->map[y][x] == '1' || data->map[y][x] == 'X'
		|| (data->map[y][x] == 'C'))
	{
		data->enemies[i].emov_x = data->enemies[i].x;
		data->enemies[i].emov_y = data->enemies[i].y;
		return (0);
	}
	return (1);
}

void	set_move_enemy(t_data *data, int i)
{
	int	px;
	int	py;
	int	ex;
	int	ey;

	px = data->player_x;
	py = data->player_y;
	ex = data->enemies[i].x;
	ey = data->enemies[i].y;
	if (px < ex)
	{
		data->enemies[i].emov_x = ex - 1;
		data->enemies[i].emov_y = ey;
		data->enemies[i].enemy = data->enemy_left;
		if (check_move_enemy(data, i))
			return ;
	}
	if (px > ex)
	{
		data->enemies[i].emov_x = ex + 1;
		data->enemies[i].emov_y = ey;
		data->enemies[i].enemy = data->enemy_right;
		if (check_move_enemy(data, i))
			return ;
	}
	if (py < ey)
	{
		data->enemies[i].emov_x = ex;
		data->enemies[i].emov_y = ey - 1;
		data->enemies[i].enemy = data->enemy_up;
		if (check_move_enemy(data, i))
			return ;
	}
	if (py > ey)
	{
		data->enemies[i].emov_x = ex;
		data->enemies[i].emov_y = ey + 1;
		data->enemies[i].enemy = data->enemy_down;
		if (check_move_enemy(data, i))
			return ;
	}
}

void	move_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		set_move_enemy(data, i);
		if (check_move_enemy(data, i))
		{
			data->map[data->enemies[i].y][data->enemies[i].x] = '0';
			data->enemies[i].x = data->enemies[i].emov_x;
			data->enemies[i].y = data->enemies[i].emov_y;
		}
		i++;
	}
}
