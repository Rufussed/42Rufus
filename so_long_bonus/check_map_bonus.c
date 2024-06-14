/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:32:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/13 16:34:37 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_rectangular(t_data *data)
{
	size_t	i;

	data->map_width = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != data->map_width)
			return (error_set(NOT_RECTANGLE_ERROR));
		i++;
	}
	data->map_height = i;
	return (1);
}

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
				&& data->map[i][j] != 'E' && data->map[i][j] != 'X')
				return (error_set(INVALID_CHAR_ERROR));
			j++;
		}
		i++;
	}
	if (data->map_width > MAX_MAP_WIDTH || data->map_height > MAX_MAP_HEIGHT)
		return (error_set(MAP_OVERSIZE_ERROR));
	if (data->map_width < 3 || data->map_height < 3)
		return (error_set(MAP_UNDERSIZE_ERROR));
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
					return (error_set(BAD_WALLS_ERROR));
			}
			if (j == 0 || j == data->map_width - 1)
			{
				if (data->map[i][j] != '1')
					return (error_set(BAD_WALLS_ERROR));
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
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (error_set(PLAYER_ERROR));
	return (1);
}

int	check_game_objects(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->key_count++;
			if (data->map[i][j] == 'E')
				data->exit_count++;
			if (data->map[i][j] == 'E' || data->map[i][j] == 'C' 
				|| data->map[i][j] == '0')
				data->floor_count++;
			j++;
		}
		i++;
	}
	if (data->exit_count != 1)
		return (error_set(EXITS_ERROR));
	if (data->key_count == 0)
		return (error_set(COLLECTIBLES_ERROR));
	return (1);
}
