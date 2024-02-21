/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:52:38 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/09/16 12:02:45 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	search_player(t_game_data *data)
{
	t_player	player;
	int			tmp;
	size_t		p_count;
	size_t		count;
	size_t		i;

	i = 0;
	tmp = data->map_height;
	count = 0;
	p_count = 0;
	while (tmp--)
	{
		p_count = my_strchr(data->game_map[i], 'P');
		if (p_count != 0)
			break ;
		i++;
		count++;
	}
	player.p_x = p_count;
	player.p_y = count;
	return (player);
}

static int	check_pce(t_game_data *data, int y, int x)
{
	if (data->game_map[y][x] != '1')
	{
		if (data->coin_count != 0 && data->game_map[y][x] == 'E')
			return (-1);
		else if (data->game_map[y][x] == 'E')
		{
			data->game_map[y][x] = 'P';
			return (1);
		}
		else if (data->game_map[y][x] == 'C')
			data->coin_count--;
		data->game_map[y][x] = 'P';
		return (0);
	}
	return (-1);
}

void	movement_player(t_game_data *data, char c)
{
	t_player	player;
	int			frag;

	player = search_player(data);
	frag = 0;
	if (c == 'w')
		frag = check_pce(data, player.p_y - 1, player.p_x);
	else if (c == 'd')
		frag = check_pce(data, player.p_y, player.p_x + 1);
	else if (c == 's')
		frag = check_pce(data, player.p_y + 1, player.p_x);
	else if (c == 'a')
		frag = check_pce(data, player.p_y, player.p_x - 1);
	if (frag == 0 || frag == 1)
	{
		data->game_map[player.p_y][player.p_x] = '0';
		data->player_walk_count++;
		ft_printf("%d歩目\n", data->player_walk_count);
	}
	create_map(data);
	if (frag == 1)
	{
		ft_printf("GAME CLEAR\n");
		close_window(data);
	}
}
