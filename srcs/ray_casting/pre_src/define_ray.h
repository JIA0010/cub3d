/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:35:11 by cjia              #+#    #+#             */
/*   Updated: 2024/02/21 15:10:22 by cjia             ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}			t_map;

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

void		map_hight_and_width(char **argv, t_map *data);
void		import_map(char **argv, t_map *map);
void		error(char *str);
size_t		ft_strnlen(const char *str);
void		make_mapx_memory(t_map *data);
void		set_null(t_map *data);
void		start_game(t_ray data, t_map map);

#endif
