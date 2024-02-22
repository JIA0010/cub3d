/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:07 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/02/22 12:27:10 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game_data	place_images_in_game(t_game_data data)
{
	int	x;
	int	y;

	data.player = mlx_xpm_file_to_image(data.graphics_context, P_IMG_PLAYER, &x,
			&y);
	data.grass = mlx_xpm_file_to_image(data.graphics_context, P_IMG_GRASS, &x,
			&y);
	data.wood = mlx_xpm_file_to_image(data.graphics_context, P_IMG_WOOD, &x,
			&y);
	data.goal = mlx_xpm_file_to_image(data.graphics_context, P_IMG_GOAL, &x,
			&y);
	data.item = mlx_xpm_file_to_image(data.graphics_context, P_IMG_ITEM, &x,
			&y);
	return (data);
}

static t_data	*make_image(t_game_data *data, char c)
{
	t_data	img;

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
		all_free(data->game_map);
		error("Image acquisition failure");
	}
	return (img.img);
}

static void	get_map(t_game_data *data, char *line, size_t k)
{
	t_data	img;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		img.img = make_image(data, line[i]);
		// img.addr = mlx_get_data_addr(img.img, &img.pixel, &img.len, &img.end);
		mlx_put_image_to_window(data->graphics_context, data->window, img.img,
			j, k);
		j += 40;
		i++;
	}
}

int	create_map(t_game_data *data)
{
	int		tmp;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	tmp = data->map_height;
	while (tmp--)
	{
		get_map(data, data->game_map[i], k);
		i++;
		k += 40;
	}
	return (0);
}
