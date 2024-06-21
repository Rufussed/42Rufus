/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:09 by rlane             #+#    #+#             */
/*   Updated: 2024/06/19 12:58:48 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_number_images(t_data *data)
{
	if (data->n9)
		mlx_destroy_image(data->mlx_ptr, data->n9);
	if (data->n8)
		mlx_destroy_image(data->mlx_ptr, data->n8);
	if (data->n7)
		mlx_destroy_image(data->mlx_ptr, data->n7);
	if (data->n6)
		mlx_destroy_image(data->mlx_ptr, data->n6);
	if (data->n5)
		mlx_destroy_image(data->mlx_ptr, data->n5);
	if (data->n4)
		mlx_destroy_image(data->mlx_ptr, data->n4);
	if (data->n3)
		mlx_destroy_image(data->mlx_ptr, data->n3);
	if (data->n2)
		mlx_destroy_image(data->mlx_ptr, data->n2);
	if (data->n0)
		mlx_destroy_image(data->mlx_ptr, data->n0);
	if (data->n1)
		mlx_destroy_image(data->mlx_ptr, data->n1);
}

void	free_enemy_ui_images(t_data *data)
{
	free_number_images(data);
	if (data->enemy_up)
		mlx_destroy_image(data->mlx_ptr, data->enemy_up);
	if (data->enemy_down)
		mlx_destroy_image(data->mlx_ptr, data->enemy_down);
	if (data->enemy_left)
		mlx_destroy_image(data->mlx_ptr, data->enemy_left);
	if (data->enemy_right)
		mlx_destroy_image(data->mlx_ptr, data->enemy_right);
	if (data->win)
		mlx_destroy_image(data->mlx_ptr, data->win);
	if (data->lose)
		mlx_destroy_image(data->mlx_ptr, data->lose);
	if (data->green_steps)
		mlx_destroy_image(data->mlx_ptr, data->green_steps);
	if (data->red_steps)
		mlx_destroy_image(data->mlx_ptr, data->red_steps);
	if (data->black)
		mlx_destroy_image(data->mlx_ptr, data->black);
}

void	free_elf2_images(t_data *data)
{
	if (data->elf_dead)
		mlx_destroy_image(data->mlx_ptr, data->elf_dead);
	if (data->elf_up2)
		mlx_destroy_image(data->mlx_ptr, data->elf_up2);
	if (data->elf_down2)
		mlx_destroy_image(data->mlx_ptr, data->elf_down2);
	if (data->elf_left2)
		mlx_destroy_image(data->mlx_ptr, data->elf_left2);
	if (data->elf_right2)
		mlx_destroy_image(data->mlx_ptr, data->elf_right2);
}

void	close_win_free_mlx(t_data *data)
{
	free_enemy_ui_images(data);
	free_elf2_images(data);
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->elf_up)
		mlx_destroy_image(data->mlx_ptr, data->elf_up);
	if (data->elf_down)
		mlx_destroy_image(data->mlx_ptr, data->elf_down);
	if (data->elf_left)
		mlx_destroy_image(data->mlx_ptr, data->elf_left);
	if (data->elf_right)
		mlx_destroy_image(data->mlx_ptr, data->elf_right);
	if (data->key)
		mlx_destroy_image(data->mlx_ptr, data->key);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
