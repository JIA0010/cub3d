/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:06:35 by cjia              #+#    #+#             */
/*   Updated: 2023/09/16 10:13:52 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_road(t_game_data *data, int y, int x)
{
	if (data->game_map[y][x] != '1')
	{
		if (data->game_map[y][x] == 'E')
		{
			data->endpoint_count = 0;
			return (false);
		}
		if (data->game_map[y][x] == 'C')
			data->coin_count--;
		data->game_map[y][x] = '1';
		return (true);
	}
	return (false);
}

static void	search(t_game_data *data, int y, int x)
{
	if (!check_road(data, y, x))
		return ;
	search(data, y - 1, x);
	search(data, y, x + 1);
	search(data, y + 1, x);
	search(data, y, x - 1);
}

void	map_search_all(t_game_data *data)
{
	t_player	player;

	player = search_player(data);
	data->endpoint_count = 1;
	search(data, player.p_y, player.p_x);
	if (data->coin_count == 0 && data->endpoint_count == 0)
		return ;
	error("Incorrect map");
}
