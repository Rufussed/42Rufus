/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:08:13 by rlane             #+#    #+#             */
/*   Updated: 2024/06/15 12:27:06 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_enemy(t_data *data, int x, int y)
{
	data->enemies[data->enemy_count].x = x;
	data->enemies[data->enemy_count].y = y;
}

int	check_enemies(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'X')
			{
				add_enemy(data, j, i);
				data->enemy_count++;
				if (data->enemy_count > MAX_ENEMIES)
					return (error_set(TOO_MANY_ENEMIES_ERROR));
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (1);
}
