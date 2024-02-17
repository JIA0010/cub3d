/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/17 17:12:32 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

typedef struct s_parser
{
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
}	t_parser;

typedef struct s_data
{
	struct s_parser	*parser;
}				t_data;

#endif