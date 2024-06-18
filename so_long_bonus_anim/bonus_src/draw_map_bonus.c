/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:10:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 14:52:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	object_to_map_count(t_data *data, char object_type, void *object)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == object_type)
			{
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, object,
					j * SPRITE_SIZE, i * SPRITE_SIZE);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	sprite_to_coords(t_data *data, int x, int y, void *object)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, object,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	draw_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		sprite_to_coords(data, data->enemies[i].x, data->enemies[i].y,
			data->enemies[i].enemy);
		i++;
	}
}

void	draw_game_objects(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'C')
		data->map[data->player_y][data->player_x] = '0';
	data->key_count = object_to_map_count(data, 'C', data->key);
	draw_enemies(data);
	sprite_to_coords(data, data->player_x, data->player_y, data->player);
}

void	draw_map_check_win(t_data *data)
{
	object_to_map_count(data, '1', data->wall);
	object_to_map_count(data, '0', data->floor);
	object_to_map_count(data, 'E', data->exit);
	draw_game_objects(data);
	draw_text(data);
	check_win(data);
	check_lose(data);
	mlx_do_sync(data->mlx_ptr);
}
