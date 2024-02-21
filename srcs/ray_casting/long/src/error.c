/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:18 by yoshimurahi       #+#    #+#             */
/*   Updated: 2023/09/19 12:52:17 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	limit_and_check_map(t_game_data data, int i, char **argv)
{
	if (data.map_width > 50)
		error("Incorrect map(map_size is too large)");
	if (data.map_height > 25)
		error("Incorrect map(map_size is too large)");
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i - 2] != 'e'
		|| argv[1][i - 1] != 'r')
		error("Incorrect map(map_file is not .ber)");
}

void	all_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error(char *msg)
{
	ft_printf("Error:\n%s\n", (msg));
	exit(EXIT_FAILURE);
}
