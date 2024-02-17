/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:18:17 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/17 16:26:34 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

t_data	*error_init(void)
{
	printf("srcs/init/init.c : malloc_error\n");
	return (NULL);
}

void	error_init_parser(void)
{
	printf("srcs/init/init_parser.c : malloc_error\n");
	return (NULL);
}
