/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:23:32 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/09/20 15:58:30 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	block_count_mid(t_game_data *data)
{
	int	i;

	i = 1;
	while (data->game_map[i] != NULL)
	{
		if (data->game_map[i][0] != '1')
			error("Incorrect map");
		if (data->game_map[i][data->map_width - 1] != '1')
			error("Incorrect map");
		i++;
	}
}

static void	block_count_opp(t_game_data *data)
{
	size_t	j;

	j = 0;
	while (data->game_map[0][j] && data->game_map[0][j] != '\0')
	{
		if (data->game_map[0][j] != '1')
			error("Incorrect map");
		j++;
	}
	j = 0;
	while (data->game_map[data->map_height - 1][j]
		&& data->game_map[data->map_height - 1][j] != '\0')
	{
		if (data->game_map[0][j] != '1')
			error("Incorrect map");
		j++;
	}
}

static void	check_block(t_game_data data)
{
	int	i;

	i = 0;
	while (i < data.map_height)
	{
		if (i == 0 || i == data.map_height - 1)
			block_count_opp(&data);
		else
			block_count_mid(&data);
		i++;
	}
}

static size_t	find_pce(char *line, char c)
{
	size_t	i;
	size_t	frag;

	i = 0;
	frag = 0;
	if (!line)
		error("Failed to find PCE");
	while (line[i] && line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E')
			error("Incorrect map");
		if (line[i] == c)
			frag++;
		i++;
	}
	return (frag);
}

size_t	check_map(t_game_data data)
{
	int		i;
	int		tmp;
	size_t	player;
	size_t	collectibles;
	size_t	end_point;

	i = 0;
	tmp = data.map_height;
	player = 0;
	collectibles = 0;
	end_point = 0;
	check_block(data);
	while (tmp--)
	{
		player += find_pce(data.game_map[i], 'P');
		collectibles += find_pce(data.game_map[i], 'C');
		end_point += find_pce(data.game_map[i], 'E');
		i++;
	}
	if (player != 1 || collectibles <= 0 || end_point != 1)
		error("Incorrect map");
	return (collectibles);
}
