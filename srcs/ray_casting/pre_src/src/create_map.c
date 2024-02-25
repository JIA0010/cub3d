/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:07 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/02/25 15:29:52 by yoshimurahi      ###   ########.fr       */
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


void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}



static void	set_frame_image_pixel(t_ray *ray, int x, int y)
{
	if (ray->texture_pixels[y][x] > 0)
		set_image_pixel(ray, x, y, ray->texture_pixels[y][x]);
	else if (y < ray->win_height / 2)
		set_image_pixel(ray, x, y, ray->hex_ceiling);
	else if (y < ray->win_height -1)
		set_image_pixel(ray, x, y, ray->hex_floor);
}

static void	render_frame(t_ray *data)
{
	t_ray	image;
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
			set_frame_image_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

static void	render_raycast(t_ray *data)
{
	init_texture_pixels(data);
	init_ray(data);
	ray_casting(data);
	render_frame(data);
}





static t_ray	*make_image(t_ray *data, char c)
{
	t_ray	img;

	if (c == 'P')
		img.img = data->player;
	if (c == '0')
		img.img = data->grass;
	if (c == '1')
		img.img = data->wood;
	if (c == 'E')
		img.img = data->goal;
	if (c == 'C')
		img.img = data->item;
	if (img.img == NULL)
	{
		// all_free(data->map);
		printf("c: %c\n", c);
		error("Image acquisition failure");
	}
	return (img.img);
}
