/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:06:59 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/02/25 12:39:12 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	init_texture_pixels(t_ray *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
		i++;
	}
}

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
	int			y;
	int			color;

	get_texture_index(ray);
	ray->x1 = (int)(ray->wall_x * ray->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->x1 = ray->size - ray->x1 - 1;
	ray->step = 1.0 * ray->size / ray->line_height;
	ray->pos = (ray->draw_start - ray->win_height / 2
			+ ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->y1 = (int)ray->pos & (ray->size - 1);
		ray->pos += ray->step;
		color = ray->textures[ray->index][ray->size * ray->y1 + ray->x1];
		if (ray->index == NORTH || ray->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			ray->texture_pixels[y][x] = color;
		y++;
	}
}
