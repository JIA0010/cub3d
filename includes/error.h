/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/22 16:12:06 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

bool	check_error_arg(int argc, char **argv);
bool	check_argv(char **argv);
bool	error_argc(void);
bool	error_argv(void);
t_data	*error_init(void);
bool	error_init_parser(void);
bool	error_parser_all(void);
bool	error_parser_path(void);
bool	error_parser_floor_rgb(void);
bool	error_parser_ceiling_rgb(void);
bool	error_parser_map(void);
bool	error_player(void);
bool	error_map(t_data *data);

#endif