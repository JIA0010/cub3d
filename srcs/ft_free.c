/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:48:27 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/27 09:01:54 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_parser(t_data *data);

void		ft_free(t_data *data)
{
	ft_free_parser(data);
	if (data->player_pos)
		free(data->player_pos);
	if (data)
		free(data);
}

static void	ft_free_parser(t_data *data)
{
	size_t	x;

	x = 0;
	if (data->parser->all)
		free(data->parser->all);
	if (data->parser->path_north)
		free(data->parser->path_north);
	if (data->parser->path_south)
		free(data->parser->path_south);
	if (data->parser->path_west)
		free(data->parser->path_west);
	if (data->parser->path_east)
		free(data->parser->path_east);
	while (data->parser->map[x] != NULL)
	{
		free(data->parser->map[x]);
		x++;
	}
	if (data->parser->map)
		free(data->parser->map);
	if (data->parser)
		free(data->parser);
}
