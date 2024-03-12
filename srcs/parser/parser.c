/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:09 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/12 15:20:22 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/error.h"
#include "../../includes/init.h"

bool	parser(t_data *data, char *file)
{
	if (all(data, file) == false)
		return (printf("parser/all: malloc or read error\n"), false);
	if (path(data) == false)
		return (printf("parser/path: texture path error\n"), false);
	if (floor_rgb(data) == false)
		return (printf("parser/floor_rgb: floor_rgb error\n"), false);
	if (ceiling_rgb(data) == false)
		return (printf("parser/ceiling_rgb: ceiling_rgb error\n"), false);
	if (map(data) == false)
		return (printf("parser/map: invalid character\n"), false);
	if (error_all(data) == false)
		return (printf("parser/all: invalid character\n"), false);
	return (true);
}
