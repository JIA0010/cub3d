/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:52:38 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/02/22 14:10:30 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

size_t	my_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

// t_ray	search_player(t_ray *data)
// {
// 	t_ray	player;
// 	int		tmp;
// 	size_t	p_count;
// 	size_t	count;
// 	size_t	i;

// 	i = 0;
// 	tmp = data->map_height;
// 	count = 0;
// 	p_count = 0;
// 	while (tmp--)
// 	{
// 		p_count = my_strchr(data->map[i], 'P');
// 		if (p_count != 0)
// 			break ;
// 		i++;
// 		count++;
// 	}
// 	player.p_x = p_count;
// 	player.p_y = count;
// 	return (player);
// }

// void	movement_player(t_ray *data, char c)
// {
// 	t_ray	player;
// 	int		frag;

// 	player = search_player(data);
// 	frag = 0;
// 	// if (c == 'w')
// 	// 	frag = check_pce(data, player.p_y - 1, player.p_x);
// 	// else if (c == 'd')
// 	// 	frag = check_pce(data, player.p_y, player.p_x + 1);
// 	// else if (c == 's')
// 	// 	frag = check_pce(data, player.p_y + 1, player.p_x);
// 	// else if (c == 'a')
// 	// 	frag = check_pce(data, player.p_y, player.p_x - 1);
// 	// create_map(data);
// 	if (frag == 1)
// 	{
// 		ft_printf("GAME CLEAR\n");
// 		// close_window(data);
// 	}
// }

t_ray	search_player(t_ray *data)
{
	t_ray	player;
	int		tmp;
	size_t	p_count;
	size_t	count;
	size_t	i;

	i = 0;
	tmp = data->map_height;
	count = 0;
	p_count = 0;
	while (tmp--)
	{
		p_count = my_strchr(data->map[i], 'P');
		if (p_count != 0)
			break ;
		i++;
		count++;
	}
	player.p_x = p_count;
	player.p_y = count;
	return (player);
}

static int	check_pce(t_ray *data, int y, int x)
{
	if (data->map[y][x] != '1')
	{
		if (data->map[y][x] == 'E')
		{
			data->map[y][x] = 'P';
			return (1);
		}
		data->map[y][x] = 'P';
		return (0);
	}
	return (-1);
}

void	movement_player(t_ray *data, char c)
{
	t_ray	player;
	int		frag;

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
		data->map[player.p_y][player.p_x] = '0';
	}
	create_map(data);
	if (frag == 1)
	{
		ft_printf("GAME CLEAR\n");
		close_window(data);
	}
}
