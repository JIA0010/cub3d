/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:45:25 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/10 15:54:28 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

bool	check_error_arg(int argc, char **argv);
bool	check_argv(char **argv);
bool	error_argc(void);
bool	error_argv(void);
bool	error_all(t_data *data);
bool	error_map(t_data *data);
bool	error_floodfill(t_data *data);

#endif