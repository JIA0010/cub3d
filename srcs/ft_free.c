/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:48:27 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/19 15:17:06 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"

static void	ft_free_parser(t_data *data);

void	ft_free(t_data *data)
{
	ft_free_parser(data);
	if (data->player_pos != NULL)
		free(data->player_pos);
	if (data != NULL)
		free(data);
}

static void	ft_free_parser(t_data *data)
{
	size_t	x;

	x = 0;
	if (data->map->all != NULL)
		free(data->map->all);
	if (data->map->path_north != NULL)
		free(data->map->path_north);
	if (data->map->path_south != NULL)
		free(data->map->path_south);
	if (data->map->path_west != NULL)
		free(data->map->path_west);
	if (data->map->path_east != NULL)
		free(data->map->path_east);
	while (data->map->map != NULL && data->map->map[x] != NULL)
	{
		free(data->map->map[x]);
		x++;
	}
	if (data->map->map != NULL)
		free(data->map->map);
	if (data->map != NULL)
		free(data->map);
}
