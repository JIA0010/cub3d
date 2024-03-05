/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:30:14 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/03 12:10:29 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	set_frame_image_pixel(t_ray *ray, t_img *image, int x, int y)
{
	if (ray->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, ray->texture_pixels[y][x]);
	else if (y < ray->win_height / 2)
		set_image_pixel(image, x, y, ray->hex_ceiling);
	else if (y < ray->win_height -1)
		set_image_pixel(image, x, y, ray->hex_floor);
}

static void drawing_image(t_ray *ray, t_img *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < ray->win_height)
	{
		x = 0;
		while (x < ray->win_width)
		{
			set_frame_image_pixel(ray, image, x, y);
			x++;
		}
		y++;
	}
}

void	draw_image_to_window(t_ray *data)
{
	t_img	image;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	drawing_image(data, &image);
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);//なぜイメージをすぐ消すのかをゆいなさんに説明
	mlx_destroy_image(data->mlx, image.img);
}