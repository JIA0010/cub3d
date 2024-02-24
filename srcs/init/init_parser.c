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

bool	init_parser(t_data *data)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		return (false);
	return (true);
}

bool	init_map(t_data *data, char *line)
{
	size_t	x;
	size_t	x_len;
	size_t	z_len;

	x = 0;
	x_len = map_x_len(line);
	z_len = map_z_len(line);
	data->map->map = malloc(sizeof(char *) * (x_len + 1));
	if (data->map->map == NULL)
		return (false);
	while (x < x_len)
	{
		data->map->map[x] = malloc(sizeof(char) * (z_len + 1));
		if (data->map->map[x] == NULL)
			return (false);
		x++;
	}
	return (true);
}
