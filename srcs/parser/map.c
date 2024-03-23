/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:08 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/23 13:46:22 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/init.h"
#include "../../includes/error.h"

static char	*map_line(t_data *data);
static void	map_double_line(t_data *data, char *line, size_t x, size_t z);
static bool	space_check(char *all, size_t *i);
static bool	is_not_map(char *all, size_t i);
//x(+east(left))(-west(right))
//z(+south(down))(-north(top))
//map[x][z]

bool	map(t_data *data)
{
	char	*line;

	line = map_line(data);
	if (line == NULL)
		return (false);
	if (init_map(data, line) == false)
		return (false);
	data->map->map_width = map_x_len(line);
	data->map->map_hight = map_z_len(line);
	if (data->map->map_width >= 100 || data->map->map_hight >= 100)
		return (false);
	map_double_line(data, line, 0, 0);
	if (error_map(data) == false)
		return (false);
	return (true);
}

static char	*map_line(t_data *data)
{
	char	*line;
	char	*all;
	size_t	i;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0')
	{
		if (is_not_map(all, i) == true)
		{
			while (all[i] != '\0' && all[i] != '\n')
				i++;
		}
		else if (all[i] == '1' || all[i] == '0' || all[i] == 'N'
			|| all[i] == 'S' || all[i] == 'E' || all[i] == 'W')
			break ;
		else if ((all[i] == '	' || all[i] == ' ')
			&& space_check(all, &i) == true)
			break ;
		else if (all[i] != '\n')
			return (NULL);
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
			x = 0;
			z++;
		}
		else
		{
			data->map->map[x][z] = line[i];
			x++;
		}
		i++;
	}
	data->map->map[data->map->map_width] = NULL;
	x = 0;
	z++;
	while (data->map->map[x] != NULL)
	{
		data->map->map[x][z] = '\0';
		x++;
	}
}

static bool	space_check(char *all, size_t *i)
{
	size_t	index;

	index = *i;
	while (all[index] != '\0' && all[index] != '\n')
	{
		if (is_not_map(all, index) == true)
		{
			while (all[index] != '\0' && all[index] != '\n')
				index++;
			*i = index;
			return (false);
		}
		else if (all[index] == '1' || all[index] == '0' || all[index] == 'N'
			|| all[index] == 'S' || all[index] == 'E' || all[index] == 'W')
			return (true);
		index++;
	}
	*i = index;
	return (false);
}

static bool	is_not_map(char *all, size_t i)
{
	if ((all[i] == 'N' && all[i + 1] != '\0' && all[i + 1] == 'O')
		|| (all[i] == 'S' && all[i + 1] != '\0' && all[i + 1] == 'O')
		|| (all[i] == 'W' && all[i + 1] != '\0' && all[i + 1] == 'E')
		|| (all[i] == 'E' && all[i + 1] != '\0' && all[i + 1] == 'A')
		|| (all[i] == 'F') || (all[i] == 'C'))
		return (true);
	return (false);
}
