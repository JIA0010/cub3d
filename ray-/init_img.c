/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:36:30 by cjia              #+#    #+#             */
/*   Updated: 2024/03/13 10:42:48 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

bool	init_floor_ceiling(t_ray *data, t_data *data_yhi)
{
	data->rgb_floor = malloc(sizeof(int) * 3);
	if (!data->rgb_floor)
		return (error("Failed to allocate memory"), false);
	data->rgb_floor[0] = data_yhi->map->floor_r;
	data->rgb_floor[1] = data_yhi->map->floor_g;
	data->rgb_floor[2] = data_yhi->map->floor_b;
	data->rgb_ceiling = malloc(sizeof(int) * 3);
	if (!data->rgb_ceiling)
		return (error("Failed to allocate memory"), false);
	data->rgb_ceiling[0] = data_yhi->map->ceiling_r;
	data->rgb_ceiling[1] = data_yhi->map->ceiling_g;
	data->rgb_ceiling[2] = data_yhi->map->ceiling_b;
	data->hex_ceiling = convert_rgb_to_hex(data->rgb_ceiling);
	data->hex_floor = convert_rgb_to_hex(data->rgb_floor);
	return (true);
}

void	init_texture_img(t_ray *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->size,
			&data->size);
	if (image->img == NULL)
		clean_exit(data, err_msg("mlx", "Could not create mlx image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_img(t_ray *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		clean_exit(data, err_msg("mlx", "Could not create mlx image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
