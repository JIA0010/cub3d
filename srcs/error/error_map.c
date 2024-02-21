/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:35 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 14:41:59 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"
#include "../../includes/parser.h"

static bool	check_map_closed(t_data *data);

bool	error_map(t_data *data)
{
	char	**map;
	size_t	x;
	size_t	z;

	map = data->parser->map;
	z = 0;
	while (1)
	{
		x = 0;
		if (map[x][z] == '\0')
			break ;
		while (map[x] != NULL)
		{
			if (map[x][z] != '1' && map[x][z] != '0' && map[x][z] != 'N'
				&& map[x][z] != 'S' && map[x][z] != 'E' && map[x][z] != 'W'
				&& map[x][z] != ' ')
				return (false);
			x++;
		}
		z++;
	}
	if (check_map_closed(data) == false)
		return (false);
	return (true);
}

static bool	check_map_closed(t_data *data)
{
	floodfill();
	(void)data;
	return (true);
}
