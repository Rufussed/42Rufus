/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:06:12 by rufus             #+#    #+#             */
/*   Updated: 2024/06/16 18:39:38 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_more_ui_tiles(t_data *data)
{
	int	img_width;
	int	img_height;

	ft_printf("Loading more UI tiles\n");

	data->red_steps = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/red_steps.xpm", &img_width, &img_height);
	data->green_steps = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/green_steps.xpm", &img_width, &img_height);
	data->black = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/black.xpm", &img_width, &img_height);
	data->n1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/1.xpm", &img_width, &img_height);
	data->n2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/2.xpm", &img_width, &img_height);
	data->n3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/3.xpm", &img_width, &img_height);
	data->n4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/4.xpm", &img_width, &img_height);
	data->n5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/5.xpm", &img_width, &img_height);
	if (data->red_steps == NULL || data->green_steps == NULL
		|| data->n1 == NULL || data->n2 == NULL || data->n3 == NULL
		|| data->n4 == NULL || data->n5 == NULL || data->black == NULL)
		exit(MLX_ERROR);
}

void	load_ui_tiles(t_data *data)
{
	int	img_width;
	int	img_height;

	load_more_ui_tiles(data);
	data->n6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/6.xpm", &img_width, &img_height);
	data->n7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/7.xpm", &img_width, &img_height);
	data->n8 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/8.xpm", &img_width, &img_height);
	data->n9 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/9.xpm", &img_width, &img_height);
	data->n0 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/0.xpm", &img_width, &img_height);
	data->win = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/win.xpm", &img_width, &img_height);
	data->lose = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/lose.xpm", &img_width, &img_height);
	if (data->n1 == NULL || data->n2 == NULL || data->n3 == NULL
		|| data->n4 == NULL || data->n5 == NULL || data->n6 == NULL
		|| data->n7 == NULL || data->n8 == NULL || data->n9 == NULL
		|| data->n0 == NULL || data->win == NULL || data->lose == NULL)
		exit(MLX_ERROR);
}

void	*digit_to_sprite(t_data *data, char n)
{
	if (n == '0')
		return (data->n0);
	if (n == '1')
		return (data->n1);
	if (n == '2')
		return (data->n2);
	if (n == '3')
		return (data->n3);
	if (n == '4')
		return (data->n4);
	if (n == '5')
		return (data->n5);
	if (n == '6')
		return (data->n6);
	if (n == '7')
		return (data->n7);
	if (n == '8')
		return (data->n8);
	if (n == '9')
		return (data->n9);
	return (NULL);
}

void	int_to_sprites(t_data *data, int n, int map_x, int map_y)
{
	char	*str;
	void	*sprite;
	size_t	i;
	int		x;
	int		y;

	x = map_x * SPRITE_SIZE;
	y = map_y * SPRITE_SIZE;
	i = 0;
	str = ft_itoa(n);
	while (i < ft_strlen(str))
	{
		sprite = digit_to_sprite(data, str[i]);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			sprite, x + (i * 32), y);
		i++;
	}
	free(str);
}

void	draw_text(t_data *data)
{
	int	map_x;
	int	map_y;
	int	i;

	map_x = data->map_width / 2 - 4;
	map_y = data->map_height - 1;
	i = 0;
	while (i < data->map_width)
	{
		if (i == map_x + 1 || i == map_x + 2)
			sprite_to_coords(data, i, map_y, data->black);
		else
			sprite_to_coords(data, i, map_y, data->wall);
		i++;
	}
	if (map_x < 0)
		map_x = 0;
	sprite_to_coords(data, map_x, map_y, data->green_steps);
	map_x++;
	int_to_sprites(data, data->moves, map_x, map_y);
	map_x += 3;
	sprite_to_coords(data, map_x, map_y, data->red_steps);
	map_x++;
	int_to_sprites(data, data->est_moves, map_x, map_y);
}
