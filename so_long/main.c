/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:56 by rlane             #+#    #+#             */
/*   Updated: 2024/06/09 11:59:52 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(void *param)
{
	(void)param;
	exit(0); // Exit the program
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Up)
	{	
		data->player = data->elf_up;
		data->move_y = data->player_y - 1;
	}
	if (keysym == XK_Down)
	{
		data->player = data->elf_down;
		data->move_y = data->player_y + 1;
	}
	if (keysym == XK_Left)
	{
		data->player = data->elf_left;
		data->move_x = data->player_x - 1;
	}
	if (keysym == XK_Right)
	{
		data->player = data->elf_right;
		data->move_x = data->player_x + 1;
	}
	move_player(data);
	draw_map(data);
	draw_game_objects(data);
	check_win(data);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

/* This function needs to exist, but it is useless for the moment */
int	handle_no_event(void *data)
{
	return (0);
}

void	load_tiles(t_data *data)
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

void	draw_map(t_data *data)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->wall,
					j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == '0' || data->map[i][j] == 'P'
					|| data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->floor, 
					j * SPRITE_SIZE, i * SPRITE_SIZE);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, 
					data->win_ptr, data->exit, 
					j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}	
}

void	draw_game_objects(t_data *data)
{
	int	i;
	int	j;

	data->key_count = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'C')
			{
				data->key_count++;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
					data->key, j * SPRITE_SIZE, i * SPRITE_SIZE);
			}
			if (data->player_x == j && data->player_y == i)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
					data->player, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->key_count--;
	}
}

void	check_win(t_data *data)
{
	if (data->key_count == 0 
		&& data->map[data->player_y][data->player_x] == 'E')
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_printf("You win!\n");
	}
}

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

void	move_player(t_data *data)
{
	if (check_move(data))
	{
		data->player_x = data->move_x;
		data->player_y = data->move_y;
		data->moves++;
		ft_printf("Total Moves: %d\n", data->moves);
	}
}

int	open_window(t_data *data)
{
	void	*img;
	int	img_width;
	int	img_height;
	int	win_w;
	int	win_h;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	win_w = data->map_width * SPRITE_SIZE;
	win_h = data->map_height * SPRITE_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_w, win_h, "So_Long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, EVENT_CLOSE, 0, handle_close, NULL);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	load_tiles(data);
	draw_map(data);
	draw_game_objects(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	read_map(t_data *data)
{
	char	*read_buf;
	ssize_t	bytes_read;
	int		fd;
	size_t	i;
	size_t	j;

	read_buf = malloc(BUFF_SIZE * sizeof(char));
	if (!read_buf)
		return (0);
	fd = open("map.ber", O_RDONLY);
	bytes_read = read(fd, read_buf, BUFF_SIZE);
	if (bytes_read == -1)
		return (0);
	data->map = ft_split(read_buf, '\n');
	free(read_buf);
	if (!data->map)
		return (0);
	data->map_width = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != data->map_width)
			return (0);
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	data->map_height = i;
	return (1);
}

void	free_map_content(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{
	t_data	data;

	if (!read_map(&data)  || !check_walls(&data) || !check_chars_size(&data))
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	if (!check_player(&data))
	{
		ft_printf("Error checking player\n");
		return (1);
	}
	if (!check_game_objects(&data))
	{
		ft_printf("Error checking game objects\n");
		return (1);
	}
	ft_printf("Map width = %d\n", data.map_width);
	ft_printf("Map height = %d\n\n", data.map_height);
	data.move_x = data.player_x;
	data.move_y = data.player_y;
	open_window(&data);
	free_map_content(data.map);
	return (0);
}

