/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:00 by rlane             #+#    #+#             */
/*   Updated: 2024/06/13 18:16:27 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Exit the program via window close
int	handle_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data && data->mlx_ptr)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

// Exit the program with esc
int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Up)
	{
		data->player = data->elf_up;
		data->move_y = data->player_y - 1;
	}
	if (keysym == XK_Down)
	{
		data->player = data->elf_down;
		data->move_y = data->player_y + 1;
	}
	if (keysym == XK_Left)
	{
		data->player = data->elf_left;
		data->move_x = data->player_x - 1;
	}
	if (keysym == XK_Right)
	{
		data->player = data->elf_right;
		data->move_x = data->player_x + 1;
	}
	move_player(data);
	move_enemy(data);
	draw_map_check_win(data);
	return (0);
}

/* This function needs to exist, but it is useless for the moment */
int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}
