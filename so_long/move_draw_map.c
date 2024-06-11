/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:10:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/10 15:24:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_game_objects(t_data *data)
{
	data->key_count = object_to_map_count(data, 'C', data->key);
	object_to_map_count(data, 'P', data->player);
	if (data->map[data->player_y][data->player_x] == 'C')
		data->map[data->player_y][data->player_x] = '0';
}

void	draw_map_check_win(t_data *data)
{
	object_to_map_count(data, '1', data->wall);
	object_to_map_count(data, '0', data->floor);
	object_to_map_count(data, 'E', data->exit);
	draw_game_objects(data);
	if (data->key_count == 0 
		&& data->map[data->player_y][data->player_x] == 'E')
	{
		ft_printf("You win!\n");
		mlx_loop_end(data->mlx_ptr);
	}
}

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
		if (!(data->map[data->player_y][data->player_x] == 'E'))
			data->map[data->player_y][data->player_x] = 'P';
		data->moves++;
		ft_printf("Total Moves: %d\n", data->moves);
	}
}
