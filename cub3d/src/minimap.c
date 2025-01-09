/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:30:43 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 13:30:56 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"

int	render_minimap(t_data *data)
{
	// Calculate direction line end
	int line_end_x = data->player_x + (int)(data->dir_x * LINE_LENGTH);
	int line_end_y = data->player_y + (int)(data->dir_y * LINE_LENGTH);

	// Draw player as a circle
	draw_circle(data, data->player_x, data->player_y, PLAYER_RADIUS);

	// Draw direction line
	draw_line(data, data->player_x, data->player_y, line_end_x, line_end_y);

	return (0);
}


