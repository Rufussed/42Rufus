/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:57:40 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 13:15:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy_pixel_coords(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		set_move_enemy(data, i);
		data->x[i] = data->enemies[i].x * SPRITE_SIZE;
		data->y[i] = data->enemies[i].y * SPRITE_SIZE;
		i++;
	}
}

void	nudge_enemies(t_data *data, int i)
{
	if (set_move_enemy(data, i))
	{
		sprite_to_coords(data, data->enemies[i].x, data->enemies[i].y,
			data->floor);
		sprite_to_coords(data, data->enemies[i].emov_x,
			data->enemies[i].emov_y, data->floor);
		if (data->enemies[i].direction == UP)
			data->y[i] -= ANIM_STEPS;
		else if (data->enemies[i].direction == DOWN)
			data->y[i] += ANIM_STEPS;
		else if (data->enemies[i].direction == LEFT)
			data->x[i] -= ANIM_STEPS;
		else if (data->enemies[i].direction == RIGHT)
			data->x[i] += ANIM_STEPS;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemies[i].enemy, data->x[i], data->y[i]);
	}
}

void	anim_enemies(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	set_enemy_pixel_coords(data);
	while (j < SPRITE_SIZE / ANIM_STEPS)
	{
		i = 0;
		while (i < data->enemy_count)
		{
			nudge_enemies(data, i);
			i++;
		}
		j++;
		mlx_do_sync(data->mlx_ptr);
		usleep(ANIM_DELAY);
	}
}

void	move_enemy(t_data *data)
{
	int	i;

	i = 0;
	anim_enemies(data);
	while (i < data->enemy_count)
	{
		data->map[data->enemies[i].y][data->enemies[i].x] = '0';
		data->enemies[i].x = data->enemies[i].emov_x;
		data->enemies[i].y = data->enemies[i].emov_y;
		i++;
	}
	return ;
}
