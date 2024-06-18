/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:57:29 by rlane             #+#    #+#             */
/*   Updated: 2024/06/17 14:30:40 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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



void	set_player_sprite(t_data *data)
{
	if (data->direction == UP)
	{
		data->player = data->elf_up;
		data->move_y = data->player_y - 1;
	}
	else if (data->direction == DOWN)
	{
		data->player = data->elf_down;
		data->move_y = data->player_y + 1;
	}
	else if (data->direction == LEFT)
	{
		data->player = data->elf_left;
		data->move_x = data->player_x - 1;
	}
	else if (data->direction == RIGHT)
	{
		data->player = data->elf_right;
		data->move_x = data->player_x + 1;
	}
}

void	anim_player(t_data *data, int direction)
{
	int	i;
	int	x;
	int	y;

	data->animating = TRUE;
	i = 0;
	x = data->player_x * SPRITE_SIZE;
	y = data->player_y * SPRITE_SIZE;
	while (i < SPRITE_SIZE)
	{
		sprite_to_coords(data, data->player_x, data->player_y, data->floor);
		sprite_to_coords(data, data->move_x, data->move_y, data->floor);
		if (direction == UP)
			y -= ANIM_STEPS;
		else if (direction == DOWN)
			y += ANIM_STEPS;
		else if (direction == LEFT)
			x -= ANIM_STEPS;
		else if (direction == RIGHT)
			x += ANIM_STEPS;
		ft_printf("x = %d, y = %d\n", x, y);
		ft_printf("play coords: %d, %d\n", data->player_x, data->player_y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player, x , y);
		mlx_do_sync(data->mlx_ptr);
		usleep(ANIM_DELAY);
		i += ANIM_STEPS;
	}
	data->animating = FALSE;
}

void	move_player(t_data *data)
{
	if (data->game_status != PLAYING)
		return ;
	if (check_move(data))
	{
		anim_player(data, data->direction);
		data->map[data->player_y][data->player_x] = '0';
		data->player_x = data->move_x;
		data->player_y = data->move_y;
		data->moves++;
	}
}
