/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:49 by cjia              #+#    #+#             */
/*   Updated: 2024/02/22 10:39:38 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

void	error(char *str)
{
	write(2, str, ft_strnlen(str));
	exit(1);
}

void	map_hight_and_width(char **argv, t_ray *data)
{
	int		fd;
	char	*line;
	int		height_len;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("file can't open");
	line = get_next_line(fd);
	data->map_width = ft_strnlen(line);
	free(line);
	height_len = 1;
	while (1)
	{
		if (ft_strnlen(line) != (size_t)data->map_width)
			error("Incorrect map");
		line = get_next_line(fd);
		if (line == NULL)
		{
			data->map_height = height_len;
			close(fd);
			return ;
		}
		free(line);
		height_len++;
	}
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
