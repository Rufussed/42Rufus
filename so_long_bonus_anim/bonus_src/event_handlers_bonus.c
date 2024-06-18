/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:00 by rlane             #+#    #+#             */
/*   Updated: 2024/06/18 15:55:42 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Exit the program via window close
int	handle_close(void *param)
{
	t_data	*data;

	
	data = (t_data *)param;
	if (data && data->mlx_ptr)
	{
		mlx_do_key_autorepeaton(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

// Exit the program with esc
int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_r)
		return (restart_game(data));
	if (keysym == XK_n)
		return (next_level(data));
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (data->game_status != PLAYING)
		return (0);
	if (keysym == XK_Up)
		data->direction = UP;
	if (keysym == XK_Down)
		data->direction = DOWN;
	if (keysym == XK_Left)
		data->direction = LEFT;
	if (keysym == XK_Right)
		data->direction = RIGHT;
	set_player_sprite(data);
	move_player(data);
	move_enemy(data);
	draw_map_check_win(data);
	return (1);
}

int	restart_game(t_data *data)
{
	free_map_content(data->map);
	read_map(data);
	data->moves = 0;
	data->key_count = 0;
	data->enemy_count = 0;
	data->exit_count = 0;
	data->direction = NONE;
	data->player = data->elf_down;
	check_player(data);
	check_game_objects(data);
	check_enemies(data);
	initialise_move_target(data);
	data->game_status = PLAYING;
	draw_map_check_win(data);
	return (1);
}

int	next_level(t_data *data)
{
	free_map_content(data->map);
	read_next_map(data);
	data->moves = 0;
	data->est_moves	= 0;
	estimate_moves(data);
	data->key_count = 0;
	data->enemy_count = 0;
	data->exit_count = 0;
	data->direction = NONE;
	data->player = data->elf_down;
	check_player(data);
	check_game_objects(data);
	check_enemies(data);
	initialise_move_target(data);
	data->game_status = PLAYING;
	draw_map_check_win(data);
	return (1);
}
