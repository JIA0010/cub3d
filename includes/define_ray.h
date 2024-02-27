/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:35:11 by cjia              #+#    #+#             */
/*   Updated: 2024/02/27 16:54:07 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_RAY_H
# define DEFINE_RAY_H

# include "cub3d.h"
// # include "../libft/inc/libft.h"
// # include "../minilibx/mlx.h"
// # include <fcntl.h>
// # include <limits.h>
# include <math.h>
// // # include <mlx.h>
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>

//map_textures
# define P_IMG_PLAYER "./textures/player.xpm"
# define P_IMG_GRASS "./textures/grass.xpm"
# define P_IMG_WOOD "./textures/wood.xpm"
# define P_IMG_GOAL "./textures/goal.xpm"
# define P_IMG_ITEM "./textures/creeper.xpm"

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

//keycode
# define X_ESC 65307
# define X_UP 65362
# define X_DOWN 65364
# define X_RIGHT 65363
# define X_LEFT 65361

//imac keycode
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2

/* # define WIN_WIDTH 960 */
/* # define WIN_HEIGHT 720 */
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

enum				e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum				e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_ray
{
	t_data			*data;
	//------------------------------------------ray_casting
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	//------------------------------------------map
	int				fd;
	int				line_count;
	char			*path;
	char			**file;
	int				height;
	int				width;
	int				index_end_of_map;
	//------------------------------------------long
	int				win_height;
	int				win_width;
	void			*mlx;
	void			*win;
	int				**texture_pixels;
	int				**textures;
	int				**map;
	//------------------------------------------item
	void			*wood;
	void			*player;
	void			*goal;
	void			*grass;
	void			*item;
	//------------------------------------------player
	char			dir;
	double			pos_x;
	double			pos_y;
	double			p_dir_x;
	double			p_dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
	//------------------------------------------texture_info
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x1;
	int				y1;
}					t_ray;

void				error(char *str);
void				hook(t_ray *data);
int					close_window(t_ray *data);
int					ray_casting(t_ray *data);
void				init_texture_pixels(t_ray *data);
void				update_texture_pixels(t_ray *ray, int x);
void				free_tab(void **tab);
void				set_image_pixel(t_img *img, int x, int y, int color);
void				init_ray(t_ray *ray);
int					err_msg(char *detail, char *str, int code);
void				init_img(t_ray *data, t_img *image, int width, int height);
void				init_img_clean(t_img *img);
void				clean_exit(t_ray *data, int code);
int					free_data(t_ray *data);
void				init_texinfo(t_ray *textures);
void				render_raycast(t_ray *data);
void				init_data(t_ray *data);
void				init_texture_img(t_ray *data, t_img *image, char *path);
bool				start_game(t_data *data_yhi, char **av);
int 				parse_args(t_ray *data, char **av);

#endif
