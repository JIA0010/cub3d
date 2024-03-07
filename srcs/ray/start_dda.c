/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:09:21 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/07 15:29:07 by yhirai           ###   ########.fr       */
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
	init_dda(ray);
	while (1)
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
		{
			// printf("ray->map_x[%d], ray->map_y[%d]\n", ray->map_x, ray->map_y);
			break ;
		}
	}
}
