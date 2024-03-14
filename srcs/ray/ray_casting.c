/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:31:00 by cjia              #+#    #+#             */
/*   Updated: 2024/03/13 10:34:07 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	get_raycast_info(int x, t_ray *ray)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = ray->p_dir_x + ray->plane_x * ray->camera_x;
	ray->dir_y = ray->p_dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

int	ray_casting(t_ray *ray)
{
	int	x;

	x = 0;
	while (x < ray->win_width)
	{
		get_raycast_info(x, ray);
		start_dda(ray);
		get_wall_height(ray);
		input_color_tuxture_pixels(ray, x);
		x++;
	}
	return (SUCCESS);
}
