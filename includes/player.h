/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:56 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/08 11:46:07 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

# define ONE_STEP 5

bool	player_pos(t_data *data);
bool	player_move_w(t_data *data);
bool	player_move_a(t_data *data);
bool	player_move_s(t_data *data);
bool	player_move_d(t_data *data);

#endif
