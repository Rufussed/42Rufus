/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long_bonus.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rlane <rlane@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/06 19:28:50 by rlane			 #+#	#+#			 */
/*   Updated: 2024/06/19 13:01:43 by rlane			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/src/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

// X11 event for window close (also known as "DestroyNotify")
# define EVENT_CLOSE 17

# define SPRITE_SIZE 48

# define MAX_MAP_WIDTH 40
# define MAX_MAP_HEIGHT 21

# define MIN_MAP_WIDTH 7
# define MIN_MAP_HEIGHT 5

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
# define TOO_MANY_ENEMIES_ERROR 11

# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4
# define NONE 0

# define PLAYING 1
# define WIN 0
# define LOSE -1

# define TRUE 1
# define FALSE 0

# define MAX_ENEMIES 10

# define ANIM_STEPS 12
# define ANIM_DELAY 30000

# define MAP1 "maps_bonus/map1.ber"
# define MAP2 "maps_bonus/map2.ber"
# define MAP3 "maps_bonus/map3.ber"
# define MAP4 "maps_bonus/map4.ber"
# define MAP5 "maps_bonus/map5.ber"

typedef struct s_enemy
{
	int		x;
	int		y;
	int		emov_x;
	int		emov_y;
	void	*enemy;
	int		direction;
}	t_enemy;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*elf_up;
	void	*elf_up2;
	void	*elf_down;
	void	*elf_down2;
	void	*elf_left;
	void	*elf_left2;
	void	*elf_right;
	void	*elf_right2;
	void	*elf_dead;
	void	*player;
	void	*key;
	void	*win;
	void	*lose;	
	char	**map;
	char	*map_path;
	int		map_width;
	int		map_height;
	int		game_status;
	int		player_x;
	int		player_y;
	int		move_x;
	int		move_y;
	int		direction;
	int		moves;
	int		est_moves;
	int		key_count;
	int		floor_count;
	int		exit_count;
	int		accessible_nodes;
	int		enemy_count;
	int		x[MAX_ENEMIES];
	int		y[MAX_ENEMIES];
	void	*enemy_up;
	void	*enemy_down;
	void	*enemy_left;
	void	*enemy_right;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;
	void	*n0;
	void	*red_steps;
	void	*green_steps;
	void	*black;

	t_enemy	*enemies;
}	t_data;

typedef struct s_node
{
	int	x;
	int	y;
}	t_node;

// cnv current node for queue, cnv current node for visited
typedef struct s_path_data
{
	t_node	*current_node;
	t_node	*temp_node;
	t_list	*queued_nodes;
	t_list	*visited_nodes;
}	t_path_data;

void		move_player(t_data *data);
void		draw_map_check_win(t_data *data);
void		sprite_to_coords(t_data *data, int x, int y, void *object);
void		draw_game_objects(t_data *data);
int			check_chars_size(t_data *data);
int			check_walls(t_data *data);
int			check_player(t_data *data);
int			check_game_objects(t_data *data);
void		free_data(t_data *data);
void		free_map_content(char **map);
void		close_win_free_mlx(t_data *data);
void		move_player(t_data *data);
int			read_map(t_data *data);
int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, t_data *data);
int			handle_close(void *param);
int			error_set(int error);
void		print_report(t_data *data);
void		initialise_data(t_data *data);
int			init_data_check_map(t_data *data);
void		initialise_move_target(t_data *data);
int			check_rectangular(t_data *data);
int			check_all_player_accessible_nodes(t_data *data);
void		lst_remove_front(t_list **lst);
int			check_visited_for_keys_exit(t_data *data, t_path_data *path_data);
void		find_adjacent_nodes(t_data *data, t_path_data *path_data);
void		check_and_queue_node(int x, int y, t_data *data,
				t_path_data *path_data);
void		lst_remove_front(t_list **lst);
int			ft_lstfind(t_list *lst, t_node *node);
t_path_data	*initialise_path_data(t_path_data *path_data);
void		free_path_data(t_path_data *path_data);
void		estimate_moves(t_data *data);
void		init_enemy_data(t_data *data);
int			check_enemies(t_data *data);
void		move_enemy(t_data *data);
void		check_win(t_data *data);
void		check_lose(t_data *data);
void		draw_text(t_data *data);
void		load_ui_tiles(t_data *data);
void		load_tiles(t_data *data);
int			restart_game(t_data *data);
void		set_player_sprite(t_data *data);
void		set_enemy_sprite(t_data *data, int i, int direction);
void		move_object_coords(int *x, int *y, int direction);
int			check_enemy_enemy_collision(t_data *data, int i);
int			check_move_enemy(t_data *data, int i);
int			set_move_enemy_horizontal(t_data *data, int i);
int			set_move_enemy(t_data *data, int i);
int			read_next_map(t_data *data);
int			next_level(t_data *data);
void		load_tiles(t_data *data);

#endif // SO_LONG_H
