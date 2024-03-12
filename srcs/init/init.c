/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:09:47 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/12 16:15:19 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init.h"

t_data	*init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (printf("init: malloc_error\n"), NULL);
	if (init_parser(data) == false)
		return (false);
	if (init_player(data) == false)
		return (false);
	return (data);
}
