/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:35:11 by cjia              #+#    #+#             */
/*   Updated: 2024/02/25 15:52:09 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_RAY_H
# define DEFINE_RAY_H

// # include "cub3d.h"
# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
// # include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//map_textures
# define P_IMG_PLAYER "./textures/player.xpm"
# define P_IMG_GRASS "./textures/grass.xpm"
# define P_IMG_WOOD "./textures/wood.xpm"
# define P_IMG_GOAL "./textures/goal.xpm"
# define P_IMG_ITEM "./textures/item.xpm"

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


enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};



# ifndef BONUS
#  define BONUS 1
# endif

/* # define WIN_WIDTH 960 */
/* # define WIN_HEIGHT 720 */
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

# define DIST_EDGE_MOUSE_WRAP 20

/* MINIMAP MACROS */
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

// ERROR MESSAGES
# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"


typedef struct s_ray
{
	//------------------------------------------ray_casting
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;


	//------------------------------------------map

	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;

	//------------------------------------------long

	char		**map;
	int			win_height;
	int			win_width;
	void		*mlx;
	void		*win;
	int			**texture_pixels;
	int			**textures;

	//------------------------------------------item

	void	*wood;
	void	*player;
	void	*goal;
	void	*grass;
	void	*item;

	//------------------------------------------img
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;

	//------------------------------------------player
	char	dir;
	double	pos_x;
	double	pos_y;
	double	p_dir_x;
	double	p_dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;


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

}			t_ray;


void		map_hight_and_width(char **argv, t_ray *data);
void		import_map(char **argv, t_ray *map);
void		error(char *str);
size_t		ft_strnlen(const char *str);
void		make_mapx_memory(t_ray *data);
void		set_null(t_ray *data);
void		start_game(t_ray *data);
void		hook(t_ray *data);
int			create_map(t_ray *data);
int			close_window(t_ray *data);
int			ray_casting(t_ray *data);
void	init_texture_pixels(t_ray *data);
void	update_texture_pixels(t_ray *ray, int x);
void	free_tab(void **tab);
void	set_image_pixel(t_ray *ray, int x, int y, int color);
void	init_ray(t_ray *ray);
int		err_msg(char *detail, char *str, int code);
void	init_img(t_ray *data, t_ray *image, int width, int height);
void	init_img_clean(t_ray *img);
void	clean_exit(t_ray *data, int code);
int		free_data(t_ray *data);
void	init_texinfo(t_ray *textures);
void	render_raycast(t_ray *data);



#endif
