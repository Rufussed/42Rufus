/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:57:40 by rlane             #+#    #+#             */
/*   Updated: 2024/06/13 12:36:58 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (data->moves > data->est_moves)
			ft_printf("\033[1G\033[31mMoves: %d", data->moves);
		else
			ft_printf("\033[1G\033[32mMoves: %d", data->moves);
	}
}
