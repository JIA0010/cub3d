/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:09 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/22 14:29:59 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/error.h"
#include "../../includes/init.h"

bool	parser(t_data *data, char *file)
{
	if (init_parser(data) == false)
		return (error_init_parser());
	if (all(data, file) == false)
		return (error_parser_all());
	if (path(data) == false)
		return (error_parser_path());
	if (floor_rgb(data) == false)
		return (error_parser_floor_rgb());
	if (ceiling_rgb(data) == false)
		return (error_parser_ceiling_rgb());
	if (map(data) == false)
		return (error_parser_map());
	return (true);
}
