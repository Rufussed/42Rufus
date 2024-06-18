/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:53 by rlane             #+#    #+#             */
/*   Updated: 2024/06/17 09:17:20 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_set(int error)
{
	if (error == NOT_RECTANGLE_ERROR)
		ft_printf("%s\n", "\033[31mMap is not rectangular");
	if (error == BAD_WALLS_ERROR)
		ft_printf("%s\n", "\033[31mMap has bad walls");
	if (error == COLLECTIBLES_ERROR)
		ft_printf("%s\n", "\033[31mMap has no collectibles");
	if (error == EXITS_ERROR)
		ft_printf("%s\n", "\033[31mMap exit count is not 1");
	if (error == PLAYER_ERROR)
		ft_printf("%s\n", "\033[31mMap player count is not 1");
	if (error == INVALID_CHAR_ERROR)
		ft_printf("%s\n", "\033[31mMap has invalid characters");
	if (error == MAP_OVERSIZE_ERROR)
		ft_printf("%s\n", "\033[31mMap is too big");
	if (error == MAP_UNDERSIZE_ERROR)
		ft_printf("%s\n", "\033[31mMap is too small");
	if (error == NO_VALID_PATH_ERROR)
		ft_printf("%s\n", "\033[31mUnsolvable Map");
	return (0);
}

void	estimate_moves(t_data *data)
{
	int		i;

	i = data->key_count;
	data->est_moves = data->map_width + data->map_height;
	while (i > 0)
	{
		data->est_moves += i / data->key_count
			* (data-> enemy_count * data->map_width * data->map_height) * 0.05;
		i--;
	}
}

void	print_report(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("\nMap width = %d\n", data->map_width);
	ft_printf("Map height = %d\n\n", data->map_height);
	ft_printf("Player x = %d\n", data->player_x);
	ft_printf("Player y = %d\n\n", data->player_y);
	ft_printf("Enemy count = %d\n", data->enemy_count);
	i = 0;
	while (i < data->enemy_count)
	{
		ft_printf("Enemy %d x = %d\n", i, data->enemies[i].x);
		ft_printf("Enemy %d y = %d\n\n", i, data->enemies[i].y);
		i++;
	}
	ft_printf("Estimated Moves = %d\n\n", data->est_moves);
}
