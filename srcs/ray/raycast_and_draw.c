/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:07 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/03 09:19:37 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static void	identify_texture(t_ray *data)
{
	if (data->texture_pixels)
	free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
}

void	calloc_texture_pixels(t_ray *data)
{
	int	i;
	
	i = 0;
	identify_texture(data);
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			clean_exit(data, err_msg(NULL, "Could not allocate memory", 1));
		i++;
	}
}



static void	set_frame_image_pixel(t_ray *ray, t_img *image, int x, int y)
{
	if (ray->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, ray->texture_pixels[y][x]);
	else if (y < ray->win_height / 2)
		set_image_pixel(image, x, y, ray->hex_ceiling);
	else if (y < ray->win_height -1)
		set_image_pixel(image, x, y, ray->hex_floor);
}

static void	draw_image_to_window(t_ray *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	raycast_and_draw(t_ray *data)
{
	calloc_texture_pixels(data);
	ray_casting(data);
	draw_image_to_window(data);
}
