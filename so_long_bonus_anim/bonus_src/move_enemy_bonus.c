/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:57:40 by rlane             #+#    #+#             */
/*   Updated: 2024/06/17 18:57:27 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_enemy_enemy_collision(t_data *data, int i)
{
	int	x;
	int	y;
	int	j;

	x = data->enemies[i].emov_x;
	y = data->enemies[i].emov_y;
	j = 0;
	while (j < data->enemy_count)
	{
		if (j == i)
			j++;
		if ((data->enemies[j].x == x && data->enemies[j].y == y)
			|| (data->enemies[j].emov_x == x && data->enemies[j].emov_y == y))
		{
			data->enemies[i].emov_x = data->enemies[i].x;
			data->enemies[i].emov_y = data->enemies[i].y;
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_move_enemy(t_data *data, int i)
{
	int	x;
	int	y;

	if (!check_enemy_enemy_collision(data, i))
		return (0);
	x = data->enemies[i].emov_x;
	y = data->enemies[i].emov_y;
	if (data->map[y][x] == '1' || data->map[y][x] == 'X'
		|| (data->map[y][x] == 'C' || data->map[y][x] == 'E'))
	{
		data->enemies[i].emov_x = data->enemies[i].x;
		data->enemies[i].emov_y = data->enemies[i].y;
		return (0);
	}
	return (1);
}

int	set_move_enemy_horizontal(t_data *data, int i)
{
	int	ex;
	int	ey;
	ft_printf("Set Move Enemy Horiz\n"); //debug
	ex = data->enemies[i].x;
	ey = data->enemies[i].y;
	if (data->player_x < ex)
	{
		data->enemies[i].emov_x = ex - 1;
		data->enemies[i].emov_y = ey;
		data->enemies[i].enemy = data->enemy_left;
		data->enemies[i].direction = LEFT;
		if (check_move_enemy(data, i))
			return (1);
	}
	if (data->player_x > ex)
	{
		data->enemies[i].emov_x = ex + 1;
		data->enemies[i].emov_y = ey;
		data->enemies[i].enemy = data->enemy_right;
		data->enemies[i].direction = RIGHT;
		if (check_move_enemy(data, i))
			return (1);
	}
	return (0);
}

int	set_move_enemy(t_data *data, int i)
{
	int	ex;
	int	ey;
	ft_printf("Set Move Enemy\n"); //debug
	if (set_move_enemy_horizontal(data, i))
		return (1);
	ex = data->enemies[i].x;
	ey = data->enemies[i].y;
	if (data->player_y < ey)
	{
		data->enemies[i].emov_x = ex;
		data->enemies[i].emov_y = ey - 1;
		data->enemies[i].enemy = data->enemy_up;
		data->enemies[i].direction = UP;
		if (check_move_enemy(data, i))
			return (1);
	}
	if (data->player_y > ey)
	{
		data->enemies[i].emov_x = ex;
		data->enemies[i].emov_y = ey + 1;
		data->enemies[i].enemy = data->enemy_down;
		data->enemies[i].direction = DOWN;
		if (check_move_enemy(data, i))
			return (1);
	}
	return (0);
}




void	anim_enemies(t_data *data)
{
	int	i;
	int	j;
	int	x[10];
	int	y[10];

	data->animating = TRUE;
	i = 0;
	ft_printf("Anim Enemy\n"); //debug
	ft_printf("Enemy Count = %d\n", data->enemy_count); //debug
	while (i < data->enemy_count)
	{
		ft_printf("Loop\n"); //debug
		set_move_enemy(data, i);
		ft_printf("Set Move Enemy\n"); //debug
		x[i] = data->enemies[i].x * SPRITE_SIZE;
		y[i] = data->enemies[i].y * SPRITE_SIZE;
		i++;
	}
	j = 0;
	while (j < SPRITE_SIZE)
	{
		i = 0;
		while (i < data->enemy_count)
		{
			if (check_move_enemy(data, i))
			{	
			sprite_to_coords(data, data->enemies[i].x, data->enemies[i].y,
				data->floor);
			sprite_to_coords(data, data->enemies[i].emov_x,
				data->enemies[i].emov_y, data->floor);
			if (data->enemies[i].direction == UP)
				y[i] -= ANIM_STEPS;
			else if (data->enemies[i].direction == DOWN)
				y[i] += ANIM_STEPS;
			else if (data->enemies[i].direction == LEFT)
				x[i] -= ANIM_STEPS;
			else if (data->enemies[i].direction == RIGHT)
				x[i] += ANIM_STEPS;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemies[i].enemy, x[i] , y[i]);}
			i++;
		}
		j += ANIM_STEPS;
		mlx_do_sync(data->mlx_ptr);
		usleep(ANIM_DELAY);
	}
	data->animating = FALSE;
	return ;
}

void	move_enemy(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("Move Enemy\n");
	anim_enemies(data);
	while (i < data->enemy_count)
	{
	
			data->map[data->enemies[i].y][data->enemies[i].x] = '0';
			data->enemies[i].x = data->enemies[i].emov_x;
			data->enemies[i].y = data->enemies[i].emov_y;
	
		i++;
	}
	return ;
}
