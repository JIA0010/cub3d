/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:42:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/17 17:13:37 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/init.h"
#include "../includes/parser.h"

int	main(void)
{
	t_data	*data;

	data = init();
	parser(data);
	return (0);
}
