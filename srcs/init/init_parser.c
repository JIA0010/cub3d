/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:22:46 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/22 17:02:27 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"
#include "../../includes/parser.h"

static void	init_null(t_data *data);

bool	init_parser(t_data *data)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	init_null(data);
	if (data->map == NULL)
		return (printf("Error\ninit_parser: malloc_error\n"), false);
	return (true);
}

static void	init_null(t_data *data)
{
	data->map->all = NULL;
	data->map->path_north = NULL;
	data->map->path_south = NULL;
	data->map->path_east = NULL;
	data->map->path_west = NULL;
	data->map->map = NULL;
}

bool	init_map(t_data *data, char *line)
{
	size_t	x;
	size_t	x_len;
	size_t	z_len;

	x = 0;
	x_len = map_x_len(line);
	z_len = map_z_len(line);
	data->map->map = ft_calloc(sizeof(char *), (x_len + 1));
	if (data->map->map == NULL)
		return (printf("Error\ninit_map: malloc_error\n"), false);
	while (x < x_len)
	{
		data->map->map[x] = ft_calloc(sizeof(char), (z_len + 1));
		if (data->map->map[x] == NULL)
			return (printf("Error\ninit_map: malloc_error\n"), false);
		x++;
	}
	return (true);
}
