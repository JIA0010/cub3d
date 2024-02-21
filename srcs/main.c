/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:42:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 15:15:43 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
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
		return (false);
	if (parser(data, argv[1]) == false)
		return (false);
	if (player_pos(data) == false)
		return (false);
	ft_free(data);
	return (true);
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q cub3d");
}
