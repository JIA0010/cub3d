/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:20 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 15:08:36 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

bool	init_player(t_data *data)
{
	data->player_pos = malloc(sizeof(t_pos));
	if (data->player_pos == NULL)
		return (false);
	return (true);
}
