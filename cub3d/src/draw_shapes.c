/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:14:55 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 12:18:13 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"

void	draw_circle(t_data *data, int x, int y, int radius)
{
	int	dx;
	int	dy;
	int	radius_sq;

	dx = -radius;
	radius_sq = radius * radius;
	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			if (dx * dx + dy * dy <= radius_sq)
				mlx_pixel_put(data->mlx, data->win, x + dx, y + dy, GREEN);
			dy++;
		}
		dx++;
	}
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	steps;
	float	x_inc;
	float	y_inc;
	float	current_x;
	float	current_y;
	int	i;

	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) > abs(dy)) {
	    steps = abs(dx);
	} else {
	    steps = abs(dy);
	}
	x_inc = (float)dx / steps;
	y_inc = (float)dy / steps;
	current_x = x1;
	current_y = y1;
	i = 0;
	while (i <= steps)
	{
		mlx_pixel_put(data->mlx, data->win, (int)current_x, (int)current_y, GREEN);
		current_x += x_inc;
		current_y += y_inc;
		i++;
	}
}
