/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:16:42 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 18:17:55 by yhirai           ###   ########.fr       */
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
