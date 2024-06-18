/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_win_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:10:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/14 09:50:29 by rlane            ###   ########.fr       */
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

void	draw_game_objects(t_data *data)
{
	data->key_count = object_to_map_count(data, 'C', data->key);
	sprite_to_coords(data, data->player_x, data->player_y, data->player);
	if (data->map[data->player_y][data->player_x] == 'C')
		data->map[data->player_y][data->player_x] = '0';
}

void check_win(t_data *data)
{
	if (data->key_count == 0 
		&& data->map[data->player_y][data->player_x] == 'E')
	{
		mlx_loop_end(data->mlx_ptr);
		ft_printf("\n\n\033[32m!! YOU ESCAPED THE DUNGEON !!\n");
		ft_printf("\n\033[0mTotal Moves: %d\n\n", data->moves);
		if (data->moves <= data->est_moves)
			ft_printf("\033[32mYou are %d moves under the estimated:\n\nNice!\n\n",
				data->est_moves - data->moves);
		else
		{
			ft_printf("\033[31mYou are %d moves over estimated:\n\n",
				data->moves - data->est_moves);
			ft_printf("Try harder next time!\n\n");
		}
	}
}

void check_lose(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		if (data->enemies[i].x == data->player_x
			&& data->enemies[i].y == data->player_y)
		{
			mlx_loop_end(data->mlx_ptr);
			ft_printf("\n\n\033[31m!! YOU WERE GHOSTED !!\n");
			ft_printf("\n\033[0m GAME OVER\n\n");
			ft_printf("Try again!\n\n");
		}
		i++;
	}
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

void	draw_text(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "MOVES:");

	if (data->moves > data->est_moves)
		{
			
			ft_printf("\033[1G\033[31mMoves: %d", data->moves);
		}
		else
			ft_printf("\033[1G\033[32mMoves: %d", data->moves);
}

void	draw_map_check_win(t_data *data)
{
	object_to_map_count(data, '1', data->wall);
	object_to_map_count(data, '0', data->floor);
	object_to_map_count(data, 'E', data->exit);
	draw_enemies(data);
	draw_game_objects(data);
	draw_text(data);
	check_win(data);
	check_lose(data);	
}


