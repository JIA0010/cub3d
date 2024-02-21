/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:22:46 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 12:54:53 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

static size_t	map_x_len(char *line);
static size_t	map_z_len(char *line);

bool	init_parser(t_data *data)
{
	data->parser = (t_parser *)malloc(sizeof(t_parser));
	if (data->parser == NULL)
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
	data->parser->map = malloc(sizeof(char *) * (x_len + 1));
	if (data->parser->map == NULL)
		return (false);
	while (x < x_len)
	{
		data->parser->map[x] = malloc(sizeof(char) * (z_len + 1));
		if (data->parser->map[x] == NULL)
			return (false);
		x++;
	}
	return (true);
}

static size_t	map_x_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

static size_t	map_z_len(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		len++;
		i++;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	return (len);
}
