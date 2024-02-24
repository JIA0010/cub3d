/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:05:59 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/24 17:53:34 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

void	stack_push(t_dfs *dfs, int x, int z)
{
	t_pos	pos;

	dfs->cur_x += x;
	dfs->cur_z += z;
	pos.x = dfs->cur_x;
	pos.z = dfs->cur_z;
	dfs->log_index++;
	dfs->log_stack[dfs->log_index] = pos;
}

void	stack_pop(t_dfs *dfs)
{
	t_pos	pos;
	t_pos	tmp;

	pos.x = dfs->cur_x;
	pos.z = dfs->cur_z;
	dfs->peke_index++;
	dfs->peke_stack[dfs->peke_index] = pos;
	dfs->log_index--;
	if (dfs->log_index <= 0)
		return ;
	tmp = dfs->log_stack[dfs->log_index];
	dfs->cur_x = tmp.x;
	dfs->cur_z = tmp.z;
}
