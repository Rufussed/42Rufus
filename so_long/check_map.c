/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:32:44 by rlane             #+#    #+#             */
/*   Updated: 2024/06/10 15:23:05 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_set(t_data *data, int error)
{
	if (error == NOT_RECTANGLE_ERROR)
		data->error = ft_strdup("Map is not rectangular");
	if (error == BAD_WALLS_ERROR)
		data->error = ft_strdup("Map has bad walls");
	if (error == COLLECTIBLES_ERROR)
		data->error = ft_strdup("Map has no collectibles");
	if (error == EXITS_ERROR)
		data->error = ft_strdup("Map has exit count is not 1");
	if (error == PLAYER_ERROR)
		data->error = ft_strdup("Map player count is not 1");
	if (error == INVALID_CHAR_ERROR)
		data->error = ft_strdup("Map has invalid characters");
	if (error == MAP_OVERSIZE_ERROR)
		data->error = ft_strdup("Map is too big");
	if (error == MAP_UNDERSIZE_ERROR)
		data->error = ft_strdup("Map is too small");
	return (0);
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
				&& data->map[i][j] != 'E')
				return (error_set(data, INVALID_CHAR_ERROR));
			j++;
		}
		i++;
	}
	if (data->map_width > MAX_MAP_WIDTH || data->map_height > MAX_MAP_HEIGHT)
		return (error_set(data, MAP_OVERSIZE_ERROR));
	if (data->map_width < 3 || data->map_height < 3)
		return (error_set(data, MAP_UNDERSIZE_ERROR));
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
					return (error_set(data, BAD_WALLS_ERROR));
			}
			if (j == 0 || j == data->map_width - 1)
			{
				if (data->map[i][j] != '1')
					return (error_set(data, BAD_WALLS_ERROR));
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
		return (error_set(data, PLAYER_ERROR));
	initialise_move_target(data);
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
	if (exit_count != 1)
		return (error_set(data, EXITS_ERROR));
	if (data->key_count == 0)
		return (error_set(data, COLLECTIBLES_ERROR));
	return (1);
}
