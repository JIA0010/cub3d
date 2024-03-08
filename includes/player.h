/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:56 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/08 09:50:08 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

bool	player_pos(t_data *data);
int		player_move_w(t_data *data);
int		player_move_a(t_data *data);
int		player_move_s(t_data *data);
int		player_move_d(t_data *data);

#endif
