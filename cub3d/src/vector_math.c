/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voctor_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:43:54 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 13:46:47 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub3d.h"

void rotate_vector(double *x, double *y, double angle)
{
	double old_x = *x;
	*x = old_x * cos(angle) - (*y) * sin(angle);
	*y = old_x * sin(angle) + (*y) * cos(angle);
}