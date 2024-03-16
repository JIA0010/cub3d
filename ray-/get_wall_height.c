/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:31:04 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/13 10:33:46 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	get_draw_start_end(t_ray *ray)
{
	ray->draw_start = -(ray->line_height) / 2 + ray->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->win_height / 2;
	if (ray->draw_end >= ray->win_height)
		ray->draw_end = ray->win_height - 1;
}

static void	get_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else if (ray->side == 1)
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
}

void	get_wall_height(t_ray *ray)
{
	get_wall_dist(ray);
	ray->line_height = (int)(ray->win_height / ray->wall_dist);
	get_draw_start_end(ray);
	get_wall_x(ray);
}
