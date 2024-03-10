/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:45:45 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/10 17:41:12 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/init.h"

static bool	set_player_pos(t_data *data);
static void	set_player_direction(t_data *data);

bool	player_pos(t_data *data)
{
	if (init_player(data) == false)
		return (false);
	if (set_player_pos(data) == false)
		return (printf("No player\n"), false);
	set_player_direction(data);
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
				data->player_pos->x = x + 0.1;
				data->player_pos->z = z + 0.1;
				return (true);
			}
			x++;
		}
		z++;
	}
	return (false);
}

static void	set_player_direction(t_data *data)
{
	char	c;
	size_t	x;
	size_t	z;

	x = (size_t)data->player_pos->x;
	z = (size_t)data->player_pos->z;
	c = data->map->map[x][z];
	data->player_pos->direction = c;
}
