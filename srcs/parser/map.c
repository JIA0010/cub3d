/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:08 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 13:09:44 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/init.h"

static char	*map_line(t_data *data);
static void	map_double_line(t_data *data, char *line, size_t x, size_t z);
//x(+east(left))(-west(right))
//z(+south(down))(-north(top))
//map[x][z]

bool	map(t_data *data)
{
	size_t	x;
	size_t	z;
	char	*line;
	size_t	i;

	i = 0;
	x = 0;
	z = 0;
	line = map_line(data);
	if (init_map(data, line) == false)
		return (false);
	map_double_line(data, line, 0, 0);
	return (true);
}

static char	*map_line(t_data *data)
{
	char	*line;
	char	*all;
	size_t	i;

	all = data->parser->all;
	i = 0;
	while (all[i] != '\0')
	{
		if ((all[i] == 'N' && all[i + 1] != '\0' && all[i + 1] == 'O')
			|| (all[i] == 'S' && all[i + 1] != '\0' && all[i + 1] == 'O')
			|| (all[i] == 'W' && all[i + 1] != '\0' && all[i + 1] == 'E')
			|| (all[i] == 'E' && all[i + 1] != '\0' && all[i + 1] == 'A')
			|| (all[i] == 'F') || (all[i] == 'C'))
			while (all[i] != '\0' && all[i] != '\n')
				i++;
		else if (all[i] == '1' || all[i] == '0' || all[i] == 'N'
			|| all[i] == 'S' || all[i] == 'E' || all[i] == 'W')
			break ;
		i++;
	}
	line = &all[i];
	return (line);
}

static void	map_double_line(t_data *data, char *line, size_t x, size_t z)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			data->parser->map[x] = NULL;
			x = 0;
			z++;
		}
		else
		{
			data->parser->map[x][z] = line[i];
			x++;
		}
		i++;
	}
	x = 0;
	z++;
	while (data->parser->map[x] != NULL)
	{
		data->parser->map[x][z] = '\0';
		x++;
	}
}
