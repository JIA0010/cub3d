/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:48:27 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/28 12:43:22 by yoshimurahi      ###   ########.fr       */
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
	if (data->map->all)
		free(data->map->all);
	if (data->map->path_north)
		free(data->map->path_north);
	if (data->map->path_south)
		free(data->map->path_south);
	if (data->map->path_west)
		free(data->map->path_west);
	if (data->map->path_east)
		free(data->map->path_east);
	while (data->map->map[x] != NULL)
	{
		free(data->map->map[x]);
		x++;
	}
	if (data->map->map)
		free(data->map->map);
	if (data->map)
		free(data->map);
}
