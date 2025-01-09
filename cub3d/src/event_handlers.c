/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:00 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 13:48:33 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"

// Exit the program via window close
int	handle_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data && data->mlx)
		mlx_loop_end(data->mlx);
	return (0);
}

// Exit the program with escape key
int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	double	move_speed = 5.0; // Movement speed
	double	rotation_speed = 0.1; // Rotation speed in radians

	if (keysym == XK_w) // Move forward
	{
		data->player_x += (int)(data->dir_x * move_speed);
		data->player_y += (int)(data->dir_y * move_speed);
	}
	if (keysym == XK_s) // Move backward
	{
		data->player_x -= (int)(data->dir_x * move_speed);
		data->player_y -= (int)(data->dir_y * move_speed);
	}
	if (keysym == XK_a) // Strafe left
	{
		data->player_x += (int)(data->planeX * move_speed);
		data->player_y += (int)(data->planeY * move_speed);
	}
	if (keysym == XK_d) // Strafe right
	{
		data->player_x -= (int)(data->planeX * move_speed);
		data->player_y -= (int)(data->planeY * move_speed);
	}
	if (keysym == XK_Left) // Rotate left
	{
		rotate_vector(&data->dir_x, &data->dir_y, -rotation_speed);
		rotate_vector(&data->planeX, &data->planeY, -rotation_speed);
	}
	if (keysym == XK_Right) // Rotate right
	{
		rotate_vector(&data->dir_x, &data->dir_y, rotation_speed);
		rotate_vector(&data->planeX, &data->planeY, rotation_speed);
	}

	return (0);
}

/* This function needs to exist, but it is useless for the moment */
int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}
