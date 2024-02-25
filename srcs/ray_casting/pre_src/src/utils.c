/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:49 by cjia              #+#    #+#             */
/*   Updated: 2024/02/25 15:10:27 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	error(char *str)
{
	write(2, str, ft_strnlen(str));
	exit(1);
}

// void	map_hight_and_width(char **argv, t_ray *data)
// {
// 	int		fd;
// 	char	*line;
// 	int		height_len;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		error("file can't open");
// 	line = get_next_line(fd);
// 	data->map_width = ft_strnlen(line);
// 	free(line);
// 	height_len = 1;
// 	while (1)
// 	{
// 		if (ft_strnlen(line) != (size_t)data->map_width)
// 			error("Incorrect map");
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			data->map_height = height_len;
// 			close(fd);
// 			return ;
// 		}
// 		free(line);
// 		height_len++;
// 	}
// }
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

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
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

void	init_img(t_ray *data, t_ray *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}