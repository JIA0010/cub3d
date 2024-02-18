/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:22:46 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 15:18:33 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

bool	init_parser(t_data *data)
{
	data->parser = (t_parser *)malloc(sizeof(t_parser));
	if (data->parser == NULL)
		return (false);
	return (true);
}
