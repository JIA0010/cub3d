/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:35:11 by cjia              #+#    #+#             */
/*   Updated: 2024/02/21 20:03:19 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_RAY_H
# define DEFINE_RAY_H

// # include "cub3d.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
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

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;

	//------------------------------------------

	char	**map;
	int		map_width;
	int		map_height;

	//------------------------------------------


	
	void	*graphics_context;
	void	*window;

	//------------------------------------------

	void	*wood;
	void	*player;
	void	*goal;
	void	*grass;
	void	*item;

	//------------------------------------------
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		was_hit_vertical;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		wall_hit_content;
}			t_ray;



void		map_hight_and_width(char **argv, t_ray *data);
void		import_map(char **argv, t_ray *map);
void		error(char *str);
size_t		ft_strnlen(const char *str);
void		make_mapx_memory(t_ray *data);
void		set_null(t_ray *data);
void		start_game(t_ray *data);

#endif
