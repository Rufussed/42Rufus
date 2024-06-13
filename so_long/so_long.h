/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:50 by rlane             #+#    #+#             */
/*   Updated: 2024/06/13 12:50:04 by rlane            ###   ########.fr       */
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

// X11 event for window close (also known as "DestroyNotify")
# define EVENT_CLOSE 17

# define SPRITE_SIZE 48

# define MAX_MAP_WIDTH 40
# define MAX_MAP_HEIGHT 21
// 40 * 21 + 1 = 841
# define BUFF_SIZE 1000

# define MLX_ERROR 1
# define NOT_RECTANGLE_ERROR 2
# define BAD_WALLS_ERROR 3
# define COLLECTIBLES_ERROR 4
# define EXITS_ERROR 5
# define PLAYER_ERROR 6
# define INVALID_CHAR_ERROR 7
# define MAP_OVERSIZE_ERROR 8
# define MAP_UNDERSIZE_ERROR 9
# define NO_VALID_PATH_ERROR 10

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
	int		moves;
	int		est_moves;
	int		key_count;
	int		floor_count;
	int		exit_count;
	int		accessible_nodes;
}	t_data;

typedef struct s_node
{
	int	x;
	int	y;
}	t_node;

// cnv current node for queue, cnv current node for visited
typedef struct path_data
{
	t_node	*current_node;
	t_node	*temp_node;
	t_list	*queued_nodes;
	t_list	*visited_nodes;
}	t_path_data;

void	move_player(t_data *data);
void	draw_map_check_win(t_data *data);
void	draw_game_objects(t_data *data);
int		check_chars_size(t_data *data);
int		check_walls(t_data *data);
int		check_player(t_data *data);
int		check_game_objects(t_data *data);
void	free_data(t_data *data);
void	close_win_free_mlx(t_data *data);
void	move_player(t_data *data);
int		read_map(t_data *data);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_close(void *param);
int		error_set(int error);
void	print_report(t_data *data);
void	initialise_data(t_data *data);
void	initialise_move_target(t_data *data);
int		check_rectangular(t_data *data);
int		check_all_player_accessible_nodes(t_data *data);
void	lst_remove_front(t_list **lst);
int		check_visited_for_keys_exit(t_data *data, t_path_data *path_data);
void	find_adjacent_nodes(t_data *data, t_path_data *path_data);
void	check_and_queue_node(int x, int y, t_data *data,
			t_path_data *path_data);
void	lst_remove_front(t_list **lst);
int		ft_lstfind(t_list *lst, t_node *node);
t_path_data	*initialise_path_data(t_path_data *path_data);
void	free_path_data(t_path_data *path_data);
void	estimate_moves(t_data *data);

#endif // SO_LONG_H
