/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:50 by rlane             #+#    #+#             */
/*   Updated: 2025/01/09 17:27:21 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/src/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

// X11 event for window close (also known as "DestroyNotify")
# define EVENT_CLOSE 17

# define MLX_ERROR 1



#define WIN_WIDTH 1024
#define WIN_HEIGHT 768
//minimap
#define MAP_SCALE 0.2
#define PLAYER_RADIUS 5
#define LINE_LENGTH 20
#define GREEN 0x00FF00


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*floor; // for textures
	void	*wall;

	char* map_path;
	int fd;
	
	char *north_texture_path;
	char *south_texture_path;
	char *west_texture_path;
	char *east_texture_path;
	char *floor_colour;
	char *ceiling_colour;

	int map_height;
	int map_width;
	
	char	**map; // array for map

	int	player_x;
	int	player_y;
	double	dir_x;
	double	dir_y;
	double	planeX;
	double	planeY;	
}	t_data;

int	parse_map(t_data *data);
int handle_close(void *param);
int handle_keyrelease(int keysym, t_data *data);
int handle_keypress(int keysym, t_data *data);
int handle_no_event(void *data);
void	draw_circle(t_data *data, int x, int y, int radius);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2);
int	render_minimap(t_data *data);
void rotate_vector(double *x, double *y, double angle); //rotation matrix

#endif // CUB3D_H
