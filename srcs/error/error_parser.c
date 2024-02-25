/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:16:42 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/25 17:16:44 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

bool	error_parser_all(void)
{
	printf("srcs/parser/parser.c/all(): malloc or read error\n");
	return (false);
}

bool	error_parser_path(void)
{
	printf("srcs/parser/path.c/path(): texture path error\n");
	return (false);
}

bool	error_parser_floor_rgb(void)
{
	printf("srcs/parser/floor_rgb.c/floor_rgb(): floor_rgb error\n");
	return (false);
}

bool	error_parser_ceiling_rgb(void)
{
	printf("srcs/parser/ceiling_rgb.c/ceiling_rgb(): ceiling_rgb error\n");
	return (false);
}

bool	error_parser_map(void)
{
	printf("srcs/parser/map.c/map(): map includes invalid character\n");
	return (false);
}
