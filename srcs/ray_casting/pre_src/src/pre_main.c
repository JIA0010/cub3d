/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:31 by cjia              #+#    #+#             */
/*   Updated: 2024/02/25 15:31:02 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_ray.h"

int	main(int argc, char **argv)
{
	int		i;
	t_ray	ray;

	i = 0;
	// init(&ray);
	if (argc != 2)
		error("Usage: ./cub3d <map_file>\n");
	// import_map(argv, &ray);
	start_game(&ray);
}
// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q pre_ray_casting");
// }
