/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:31:00 by cjia              #+#    #+#             */
/*   Updated: 2024/02/28 15:15:54 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"



static void	get_raycast_info(int x, t_ray *ray)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->p_dir_x = ray->p_dir_x + ray->plane_x * ray->camera_x;
	ray->p_dir_y = ray->p_dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->deltadist_x = fabs(1 / ray->p_dir_x);
	ray->deltadist_y = fabs(1 / ray->p_dir_y);
}

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

static void	start_dda(t_ray *ray)
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
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > ray->height - 0.25
			|| ray->map_x > ray->width - 1.25)
			break ;
		else if (ray->map[ray->map_y][ray->map_x] > '0')//ここ？
			hit = 1;
	}
}

static void	calculate_line_height(t_ray *ray, int x)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (ray->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + ray->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->win_height / 2;
	if (ray->draw_end >= ray->win_height)
		ray->draw_end = ray->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	ray_casting(t_ray *ray)
{
	int		x;

	x = 0;
	init_ray(ray);
	while (x < ray->win_width)
	{
		get_raycast_info(x, ray);
		start_dda(ray);
		calculate_line_height(ray, x);
		update_texture_pixels(ray, x);
		x++;
	}
	return (SUCCESS);
}