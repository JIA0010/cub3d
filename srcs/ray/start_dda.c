/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:09:21 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/03 10:18:42 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	init_dda(t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	}
}

void	start_dda(t_ray *ray)
{
	int	hit;

	hit = 0;
	init_dda(ray);
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map[ray->map_x][ray->map_y] == '1')
			hit = 1;
	}
}