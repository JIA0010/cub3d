/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:45:45 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/24 16:38:54 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/init.h"
#include "../../includes/error.h"

static bool	set_player_pos(t_data *data);

bool	player_pos(t_data *data)
{
	if (init_player(data) == false)
		return (false);
	if (set_player_pos(data) == false)
		return (error_player());
	return (true);
}

static bool	set_player_pos(t_data *data)
{
	size_t	x;
	size_t	z;

	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL)
		{
			if (data->map->map[x][z] == 'N' || data->map->map[x][z] == 'S'
				|| data->map->map[x][z] == 'E'
				|| data->map->map[x][z] == 'W')
			{
				data->player_pos->x = x;
				data->player_pos->z = z;
				return (true);
			}
			x++;
		}
		z++;
	}
	return (false);
}
