/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:07:55 by rlane             #+#    #+#             */
/*   Updated: 2024/06/19 12:58:14 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_elf2_tiles(t_data *data)
{
	int	img_width;
	int	img_height;

	data->elf_dead = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/dead.xpm", &img_width, &img_height);
	data->elf_up2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_up2.xpm", &img_width, &img_height);
	data->elf_down2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_down2.xpm", &img_width, &img_height);
	data->elf_left2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_left2.xpm", &img_width, &img_height);
	data->elf_right2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_right2.xpm", &img_width, &img_height);
	if (data->elf_up2 == NULL || data->elf_down2 == NULL 
		|| data->elf_left2 == NULL || data->elf_right2 == NULL
		|| data->elf_dead == NULL)
		exit(MLX_ERROR);
}

void	load_game_tiles(t_data *data)
{
	int	img_width;
	int	img_height;

	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit.xpm", &img_width, &img_height);
	data->key = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/key.xpm", &img_width, &img_height);
	data->elf_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_up.xpm", &img_width, &img_height);
	data->elf_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_down.xpm", &img_width, &img_height);
	data->player = data->elf_down;
	data->elf_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_left.xpm", &img_width, &img_height);
	data->elf_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/elf_right.xpm", &img_width, &img_height);
	if (data->floor == NULL || data->elf_left == NULL || data->exit == NULL
		|| data->elf_up == NULL || data->elf_down == NULL
		|| data->elf_right == NULL || data->key == NULL)
		exit(MLX_ERROR);
}

void	load_tiles(t_data *data)
{
	int	img_width;
	int	img_height;
	int	i;

	load_elf2_tiles(data);
	load_game_tiles(data);
	load_ui_tiles(data);
	data->enemy_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy_up.xpm", &img_width, &img_height);
	data->enemy_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy_down.xpm", &img_width, &img_height);
	data->enemy_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy_left.xpm", &img_width, &img_height);
	data->enemy_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy_right.xpm", &img_width, &img_height);
	if (data->enemy_up == NULL || data->enemy_left == NULL
		|| data->enemy_right == NULL || data->enemy_down == NULL)
		exit(MLX_ERROR);
	i = 0;
	while (i < data->enemy_count)
	{
		data->enemies[i].enemy = data->enemy_down;
		i++;
	}
}
