/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:56 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/05 17:15:41 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

bool	player_pos(t_data *data);
void	player_move_w(t_data *data);
void	player_move_a(t_data *data);
void	player_move_s(t_data *data);
void	player_move_d(t_data *data);

#endif