/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:06:59 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/02/29 13:41:26 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			ray->index = WEST;
		else
			ray->index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->index = SOUTH;
		else
			ray->index = NORTH;
	}
}

void	update_texture_pixels(t_ray *ray, int x)
{
	int	y;
	int	color;

	get_texture_index(ray);
	ray->x1 = (int)(ray->wall_x * ray->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		ray->x1 = ray->size - ray->x1 - 1;
	ray->step = 1.0 * ray->size / ray->line_height;
	ray->pos = (ray->draw_start - ray->win_height / 2 + ray->line_height / 2)
		* ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->y1 = (int)ray->pos & (ray->size - 1);
		ray->pos += ray->step;
		color = ray->textures[ray->index][ray->size * ray->y1 + ray->x1];
		if (ray->index == NORTH || ray->index == EAST)
			color = (color >> 1) & MASK_COLOR;
		if (color > 0)
			ray->texture_pixels[y][x] = color;
		y++;
	}
}
