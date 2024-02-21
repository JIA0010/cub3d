/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:30:02 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/09/21 15:50:05 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game_data	set_null(t_game_data data)
{
	int	tmp;
	int	i;
	int	j;

	tmp = data.map_height;
	i = 0;
	while (tmp--)
	{
		j = 0;
		while (data.game_map[i][j] && data.game_map[i][j] != '\n')
			j++;
		if (data.game_map[i][j] == '\n')
			data.game_map[i][j] = '\0';
		i++;
	}
	data.game_map[i] = NULL;
	return (data);
}

t_game_data	map_hight_and_width(char **argv, t_game_data data)
{
	int		fd;
	char	*line;
	int		height_len;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("file can't open");
	line = get_next_line(fd);
	data.map_width = ft_strnlen(line);
	free(line);
	height_len = 1;
	while (1)
	{
		if (ft_strnlen(line) != (size_t)data.map_width)
			error("Incorrect map");
		line = get_next_line(fd);
		if (line == NULL)
		{
			data.map_height = height_len;
			close(fd);
			return (data);
		}
		free(line);
		height_len++;
	}
}

t_game_data	make_mapx_memory(t_game_data data)
{
	data.game_map = (char **)malloc(sizeof(char *) * (data.map_height + 1));
	if (!data.game_map)
		error("failed to get memory");
	return (data);
}

t_game_data	import_map(char **argv, t_game_data data)
{
	int	fd;
	int	i;
	int	tmp;

	data = map_hight_and_width(argv, data);
	tmp = data.map_height;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("file is having something wrong");
	data = make_mapx_memory(data);
	i = 0;
	while (tmp--)
	{
		data.game_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	set_null(data);
	return (data);
}
