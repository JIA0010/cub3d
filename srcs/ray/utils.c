/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:49 by cjia              #+#    #+#             */
/*   Updated: 2024/03/19 15:15:54 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

size_t	ft_strnlen(const char *str)
{
	size_t	size;

	if (!str)
		error("Failed to get length");
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

int	err_msg(char *detail, char *str, int code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(detail, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" "RESET", 2);
	return (code);
}

void	clean_exit(t_ray *data, int code)
{
	if (!data)
		exit(code);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	ft_free(data->data);
	free_data(data);
	exit(code);
}

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}
