/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/09 11:27:22 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/src/libft.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

# define BUFF_SIZE 10000

# define MLX_ERROR 1

# define SPRITE_SIZE 48

# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*elf_up;
	void	*elf_down;
	void	*elf_left;
	void	*elf_right;
	void	*player;
	void	*key;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		move_x;
	int		move_y;
	int		key_count;
}	t_data;

void	move_player(t_data *data);
void	draw_map(t_data *data);
void	draw_game_objects(t_data *data);
void	check_win(t_data *data);
int     check_chars_size(t_data *data);
int     check_walls(t_data *data);
int     check_player(t_data *data);
int     check_game_objects(t_data *data);

#endif // SO_LONG_H
