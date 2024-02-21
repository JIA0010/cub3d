/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:09 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 13:14:24 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/error.h"
#include "../../includes/init.h"

bool	parser(t_data *data, char *file)
{
	// size_t	x;
	// size_t	z;

	if (init_parser(data) == false)
		return (error_init_parser());
	if (all(data, file) == false)
		return (error_parser_all());
	if (path(data) == false)
		return (error_parser_path());
	if (floor_rgb(data) == false)
		return (false);
	if (ceiling_rgb(data) == false)
		return (false);
	if (map(data) == false)
		return (false);
	// printf("-----all-----\n%s\n-------------\n", data->parser->all);
	// printf("path_north[%s]\n", data->parser->path_north);
	// printf("path_south[%s]\n", data->parser->path_south);
	// printf("path_west[%s]\n", data->parser->path_west);
	// printf("path_east[%s]\n", data->parser->path_east);
	// printf("floor_rgb[%d,%d,%d]\n", data->parser->floor_r,
	// 	data->parser->floor_g, data->parser->floor_b);
	// printf("ceiling_rgb[%d,%d,%d]\n", data->parser->ceiling_r,
	// 	data->parser->ceiling_g, data->parser->ceiling_b);
	// printf("-----map-----\n");
	// z = 0;
	// while (1)
	// {
	// 	x = 0;
	// 	if (data->parser->map[x][z] == '\0')
	// 		break ;
	// 	while (data->parser->map[x] != NULL)
	// 	{
	// 		printf("%c", data->parser->map[x][z]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	z++;
	// }
	// printf("-------------\n");
	return (true);
}
