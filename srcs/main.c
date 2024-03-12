/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/03/12 16:23:56 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"
#include "../includes/error.h"
#include "../includes/init.h"
#include "../includes/parser.h"
#include "../includes/player.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_error_arg(argc, argv) == false)
		return (false);
	data = init();
	if (data == NULL)
		return (ft_free(data), false);
	if (parser(data, argv[1]) == false)
		return (ft_free(data), false);
	if (player_pos(data) == false)
		return (ft_free(data), false);
	if (error_floodfill(data) == false)
		return (ft_free(data), false);
	start_game(data);
	exit(0);
	return (ft_free(data), true);
}


__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q cub3d");
}
