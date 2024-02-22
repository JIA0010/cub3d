/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 15:07:36 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

bool	parser(t_data *data, char *file);
bool	all(t_data *data, char *file);
bool	path(t_data *data);
bool	north(t_data *data);
bool	south(t_data *data);
bool	west(t_data *data);
bool	east(t_data *data);
bool	floor_rgb(t_data *data);
bool	floor_r(t_data *data, char *all, int *index);
bool	floor_g(t_data *data, char *all, int *index);
bool	floor_b(t_data *data, char *all, int *index);
bool	ceiling_rgb(t_data *data);
bool	ceiling_r(t_data *data, char *all, int *index);
bool	ceiling_g(t_data *data, char *all, int *index);
bool	ceiling_b(t_data *data, char *all, int *index);
bool	map(t_data *data);
size_t	map_x_len(char *line);
size_t	map_z_len(char *line);

#endif