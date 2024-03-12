/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/12 15:12:59 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

t_data	*init(void);
bool	init_parser(t_data *data);
bool	init_map(t_data *data, char *line);
bool	init_player(t_data *data);

#endif