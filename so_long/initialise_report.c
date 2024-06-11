/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_report.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:18:53 by rlane             #+#    #+#             */
/*   Updated: 2024/06/10 15:24:39 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise_data(t_data *data)
{
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->error = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->move_x = 0;
	data->move_y = 0;
	data->moves = 0;
	data->key_count = 0;
	data->floor = NULL;
	data->wall = NULL;
	data->exit = NULL;
	data->elf_up = NULL;
	data->elf_down = NULL;
	data->elf_left = NULL;
	data->elf_right = NULL;
	data->player = NULL;
	data->key = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

void	initialise_move_target(t_data *data)
{
	data->move_x = data->player_x;
	data->move_y = data->player_y;
}

void	print_report(t_data *data)
{
	ft_printf("Map width = %d\n", data->map_width);
	ft_printf("Map height = %d\n", data->map_height);
	ft_printf("Player x = %d\n", data->player_x);
	ft_printf("Player y = %d\n", data->player_y);
}
