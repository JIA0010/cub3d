/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:51:37 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 15:52:37 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

bool	error_argc(void)
{
	printf("Please enter 2 arguments\n    Ex: ./cub3d cub/ok1.cub\n");
	return (false);
}

bool	error_argv(void)
{
	printf("invalid arguments\n    Ex: ./cub3d cub/ok1.cub\n");
	return (false);
}
