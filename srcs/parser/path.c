/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:12 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/21 19:17:04 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

bool	path(t_data *data)
{
	if (north(data) == false)
		return (false);
	if (south(data) == false)
		return (false);
	if (west(data) == false)
		return (false);
	if (east(data) == false)
		return (false);
	return (true);
}

bool	north(t_data *data)
{
	char	*all;
	int		fd;
	int		i;
	int		j;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && (all[i] != 'N' || all[i + 1] != 'O'))
		i++;
	while (all[i] != '\0' && (all[i] != '.' || all[i + 1] != '/'))
		i++;
	if (all[i] == '\0')
		return (false);
	j = i;
	while (all[j] != '\0' && all[j] != ' '
		&& all[j] != '	' && all[j] != '\n')
		j++;
	data->map->path_north = ft_substr(all, i, j - i);
	fd = open(data->map->path_north, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	south(t_data *data)
{
	char	*all;
	int		fd;
	int		i;
	int		j;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && (all[i] != 'S' || all[i + 1] != 'O'))
		i++;
	while (all[i] != '\0' && (all[i] != '.' || all[i + 1] != '/'))
		i++;
	if (all[i] == '\0')
		return (false);
	j = i;
	while (all[j] != '\0' && all[j] != ' '
		&& all[j] != '	' && all[j] != '\n')
		j++;
	data->map->path_south = ft_substr(all, i, j - i);
	fd = open(data->map->path_south, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	west(t_data *data)
{
	char	*all;
	int		fd;
	int		i;
	int		j;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && (all[i] != 'W' || all[i + 1] != 'E'))
		i++;
	while (all[i] != '\0' && (all[i] != '.' || all[i + 1] != '/'))
		i++;
	if (all[i] == '\0')
		return (false);
	j = i;
	while (all[j] != '\0' && all[j] != ' '
		&& all[j] != '	' && all[j] != '\n')
		j++;
	data->map->path_west = ft_substr(all, i, j - i);
	fd = open(data->map->path_west, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	east(t_data *data)
{
	char	*all;
	int		fd;
	int		i;
	int		j;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && (all[i] != 'E' || all[i + 1] != 'A'))
		i++;
	while (all[i] != '\0' && (all[i] != '.' || all[i + 1] != '/'))
		i++;
	if (all[i] == '\0')
		return (false);
	j = i;
	while (all[j] != '\0' && all[j] != ' '
		&& all[j] != '	' && all[j] != '\n')
		j++;
	data->map->path_east = ft_substr(all, i, j - i);
	fd = open(data->map->path_east, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
