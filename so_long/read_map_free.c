/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:09 by rlane             #+#    #+#             */
/*   Updated: 2024/06/11 10:54:27 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_data *data)
{
	char	*read_buf;
	ssize_t	bytes_read;
	int		fd;

	read_buf = malloc(BUFF_SIZE * sizeof(char));
	if (!read_buf)
		return (0);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		free(read_buf);
		return (0);
	}
	bytes_read = read(fd, read_buf, BUFF_SIZE);
	if (bytes_read < 15)
	{
		free(read_buf);
		close(fd);
		return (0);
	}
	read_buf[bytes_read] = '\0';
	data->map = ft_split(read_buf, '\n');
	free(read_buf);
	close(fd);
	return (1);
}

void	free_map_content(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_map_content(data->map);
		free(data);
	}
}

void	close_win_free_mlx(t_data *data)
{
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
