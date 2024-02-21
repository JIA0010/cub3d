/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:48:27 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 13:18:55 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free(t_data *data)
{
	size_t	x;

	x = 0;
	free(data->parser->all);
	free(data->parser->path_north);
	free(data->parser->path_south);
	free(data->parser->path_west);
	free(data->parser->path_east);
	while (data->parser->map[x] != NULL)
	{
		free(data->parser->map[x]);
		x++;
	}
	free(data->parser->map);
	free(data->parser);
	free(data);
}
