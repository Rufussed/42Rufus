/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:03:49 by rufus             #+#    #+#             */
/*   Updated: 2024/06/18 13:24:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_win(t_data *data)
{
	if (data->key_count == 0
		&& data->map[data->player_y][data->player_x] == 'E')
	{
		sprite_to_coords(data, data->player_x, data->player_y, data->exit);
		sprite_to_coords(data, data->map_width / 2 - 4,
			data->map_height / 2 - 3, data->win);
		data->game_status = WIN;
		ft_printf("\n\n\033[32m!! YOU ESCAPED THE DUNGEON !!\n");
		ft_printf("\n\033[0mTotal Moves: %d\n\n", data->moves);
		if (data->moves <= data->est_moves)
			ft_printf("\033[32mYou are %d moves under estimated:\n\nNice!\n\n",
				data->est_moves - data->moves);
		else
		{
			ft_printf("\033[31mYou are %d moves over estimated:\n\n",
				data->moves - data->est_moves);
			ft_printf("Try harder next time!\n\n");
		}
	}
	return ;
}

void	check_lose(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		if (data->enemies[i].x == data->player_x
			&& data->enemies[i].y == data->player_y)
		{
			sprite_to_coords(data, data->player_x,
				data->player_y, data->elf_dead);
			sprite_to_coords(data, data->map_width / 2 - 4,
				data->map_height / 2 - 3, data->lose);
			data->game_status = LOSE;
			ft_printf("\n\n\033[31m!! YOU WERE GHOSTED !!\n");
			ft_printf("\n\033[0mGAME OVER\n\n");
			ft_printf("Try again!\n\n");
			break ;
		}
		i++;
	}
	return ;
}
