/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:07 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/03 11:36:55 by yoshimurahi      ###   ########.fr       */
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


void	raycast_and_draw(t_ray *data)
{
	calloc_texture_pixels(data);
	ray_casting(data);
	draw_image_to_window(data);
}
