/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:32:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/09 10:52:55 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars_size(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'P' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	if (data->map_width > 40 || data->map_height > 21)
		return (0);
	return (1);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i == 0 || i == data->map_height - 1)
			{
				if (data->map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == data->map_width - 1)
			{
				if (data->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(t_data *data)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

int	check_game_objects(t_data *data)
{
	int	i;
	int	j;
	int	exit_count;

	exit_count = 0;
	i = 0;
	data->key_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->key_count++;
			if (data->map[i][j] == 'E')
				exit_count++; 
			j++;
		}
		i++;
	}
	if (exit_count != 1 || data->key_count == 0)
		return (0);
	return (1);
}