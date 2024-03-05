/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:41 by hiraiyuina        #+#    #+#             */
/*   Updated: 2024/03/05 18:15:38 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include "../../includes/define_ray.h"

static bool	check_can_move(t_data *data, size_t x, size_t z);
static void	test(t_data *data);

void	player_move_w(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z - 1) == true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->z -= 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
	}
	test(data);
}

void	player_move_a(t_data *data)
{
	if (check_can_move(data, data->player_pos->x - 1, data->player_pos->z) == true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->x -= 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
	}
	test(data);
}

void	player_move_s(t_data *data)
{
	if (check_can_move(data, data->player_pos->x, data->player_pos->z + 1) == true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->z += 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
	}
	test(data);
}

void	player_move_d(t_data *data)
{
	if (check_can_move(data, data->player_pos->x + 1, data->player_pos->z) == true)
	{
		data->map->map[data->player_pos->x][data->player_pos->z] = '0';
		data->player_pos->x += 1;
		data->map->map[data->player_pos->x][data->player_pos->z] = 'P';
	}
	test(data);
}

static bool	check_can_move(t_data *data, size_t x, size_t z)
{
	if (data->map->map[x][z] == '0')
		return (true);
	return (false);
}


static void	test(t_data *data)
{
	size_t	x;
	size_t	z;
	printf("-----map-----\n");
	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL)
		{
			printf("%c", data->map->map[x][z]);
			x++;
		}
		printf("\n");
		z++;
	}
	printf("-------------\n\n");
	printf("player [x = %ld, z = %ld]\n\n", data->player_pos->x, data->player_pos->z);
}
