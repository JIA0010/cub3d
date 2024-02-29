/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:13:12 by cjia              #+#    #+#             */
/*   Updated: 2024/02/28 14:32:39 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	init_player_north_south(t_ray *player)
{
	if (player->dir == 'S')
	{
		player->p_dir_x = 0;
		player->p_dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->p_dir_x = 0;
		player->p_dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_east_west(t_ray *player)
{
	if (player->dir == 'W')
	{
		player->p_dir_x = -1;
		player->p_dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->p_dir_x = 1;
		player->p_dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

void	init_player_direction(t_ray *data)
{
	init_player_north_south(data);
	init_player_east_west(data);
}
