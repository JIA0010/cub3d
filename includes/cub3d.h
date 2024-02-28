/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/28 13:51:29 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "mlx.h"
# include "../Libft/libft.h"

# define STACK_SIZE 100

typedef struct s_pos
{
	size_t	x;
	size_t	z;
	char	direction;
}	t_pos;

typedef struct s_map
{
	char	*all;
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	char	**map;
	size_t	map_width;
	size_t	map_hight;
}	t_map;

typedef struct s_data
{
	struct s_map	*map;
	struct s_pos	*player_pos;
}				t_data;

typedef struct s_dfs
{
	t_pos	log_stack[STACK_SIZE];
	t_pos	peke_stack[STACK_SIZE];
	int		log_index;
	int		peke_index;
	size_t	cur_x;
	size_t	cur_z;
	bool	flag;
}	t_dfs;

void	ft_free(t_data *data);

#endif