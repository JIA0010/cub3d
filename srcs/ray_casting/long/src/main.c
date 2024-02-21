/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:33:32 by cjia              #+#    #+#             */
/*   Updated: 2023/09/20 16:09:28 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ===== init ====
void	init_data(t_game_data *data)
{
	data->graphics_context = 0;
	data->window = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->coin_count = 0;
	data->endpoint_count = 0;
	data->game_map = 0;
	data->player_walk_count = 0;
	data->grass = 0;
	data->player = 0;
	data->wood = 0;
	data->item = 0;
	data->goal = 0;
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

size_t	my_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

void	start_game(t_game_data data)
{
	data.graphics_context = mlx_init();
	if (!data.graphics_context)
		error("Failed to initialize graphics context");
	data.window = mlx_new_window(data.graphics_context, data.map_width * 40,
			data.map_height * 40, "so_long");
	if (!data.window)
		error("Failed to create window");
	data = place_images_in_game(data);
	create_map(&data);
	hook(&data);
	mlx_loop(data.graphics_context);
}

int	main(int argc, char **argv)
{
	t_game_data	data;
	size_t		coincopy;
	size_t		i;

	i = 0;
	coincopy = 0;
	init_data(&data);
	if (argc != 2)
		error("Usage: ./so_long <map_file>\n");
	data = import_map(argv, data);
	i = ft_strnlen(argv[1]);
	limit_and_check_map(data, i, argv);
	data.coin_count = check_map(data);
	coincopy = data.coin_count;
	map_search_all(&data);
	all_free(data.game_map);
	data = import_map(argv, data);
	data.coin_count = coincopy;
	start_game(data);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }