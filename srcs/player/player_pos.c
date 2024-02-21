/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:45:45 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 15:13:38 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/init.h"

static bool	set_player_pos(t_data *data);

bool	player_pos(t_data *data)
{
	if (init_player(data) == false)
		return (false);
	if (set_player_pos(data) == false)
		return (false);
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
		if (data->parser->map[x][z] == '\0')
			break ;
		while (data->parser->map[x] != NULL)
		{
			if (data->parser->map[x][z] == 'N' || data->parser->map[x][z] == 'S'
				|| data->parser->map[x][z] == 'E'
				|| data->parser->map[x][z] == 'W')
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
