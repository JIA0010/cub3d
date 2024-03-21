/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:51:37 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/19 16:15:38 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

bool	error_argc(void)
{
	printf("Error\nPlease enter 2 arguments\n");
	printf("    Ex: ./cub3d cub/success/success1.cub\n");
	return (false);
}

bool	error_argv(void)
{
	printf("Error\ninvalid arguments\n");
	printf("    Ex: ./cub3d cub/success/success1.cub\n");
	return (false);
}
