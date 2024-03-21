/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:20 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/19 16:16:10 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

bool	init_player(t_data *data)
{
	data->player_pos = malloc(sizeof(t_pos));
	if (data->player_pos == NULL)
		return (printf("Error\ninit_player: malloc_error\n"), false);
	return (true);
}
