/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_dfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:41:11 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/24 18:27:33 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

static void	solve(t_data *data, t_dfs *dfs);
static void	check_foot(t_dfs *dfs, t_data *data);

bool	error_map_dfs(t_data *data)
{
	t_dfs	*dfs;

	dfs = malloc(sizeof(t_dfs));
	if (dfs == NULL)
		return (printf("malloc error: srcs/error/dfs/t_dfs\n"), false);
	dfs->cur_x = data->player_pos->x;
	dfs->cur_z = data->player_pos->z;
	dfs->log_index = 0;
	dfs->peke_index = 0;
	dfs->flag = false;
	solve(data, dfs);
	if (dfs->flag == false)
		return (printf("map is not closed\n"), false);
	free(dfs);
	return (true);
}

static int	stack_overflow(t_dfs *dfs)
{
	if (dfs->log_index >= STACK_SIZE || dfs->peke_index >= STACK_SIZE)
		return (false);
	if (dfs->log_index < 0 || dfs->peke_index < 0)
		return (false);
	return (true);
}

static int	foot(t_pos *stack, int index, size_t x, size_t z)
{
	int		i;
	t_pos	tmp;

	i = 0;
	while (i < index)
	{
		tmp = stack[i];
		if (tmp.x == x && tmp.z == z)
			return (false);
		i++;
	}
	return (true);
}

static int	check_can_move(size_t x, size_t z, t_dfs *dfs, t_data *data)
{
	if (data->map->map[x][z] == '1')
		return (false);
	if (foot(dfs->log_stack, dfs->log_index, x, z) == false)
		return (false);
	if (foot(dfs->peke_stack, dfs->peke_index, x, z) == false)
		return (false);
	return (true);
}

static void	check_foot(t_dfs *dfs, t_data *data)
{
	data->map->map[dfs->cur_x][dfs->cur_z] = '*';
}

static void	show_map(t_dfs *dfs, t_data *data)
{
	size_t	x;
	size_t	z;

	check_foot(dfs, data);
	printf("-----map-----\n");
	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL)
		{
			printf("%c", data->map->map[x][z]);
			x++;
		}
		printf("\n");
		z++;
	}
	printf("-------------\n\n");
}

static void	solve(t_data *data, t_dfs *dfs)
{
	show_map(dfs, data);
	sleep(1);
	if (data->map->map[dfs->cur_x][dfs->cur_z] == ' '
		|| data->map->map[dfs->cur_x][dfs->cur_z] == '\0')
	{
		dfs->flag = false;
		return ;
	}
	if (stack_overflow(dfs) == false)
	{
		dfs->flag = true;
		return ;
	}
	if (check_can_move(dfs->cur_x - 1, dfs->cur_z, dfs, data) == true)
		stack_push(dfs, 0, -1);
	else if (check_can_move(dfs->cur_x, dfs->cur_z + 1, dfs, data) == true)
		stack_push(dfs, 1, 0);
	else if (check_can_move(dfs->cur_x + 1, dfs->cur_z, dfs, data) == true)
		stack_push(dfs, 0, 1);
	else if (check_can_move(dfs->cur_x, dfs->cur_z - 1, dfs, data) == true)
		stack_push(dfs, -1, 0);
	else
		stack_pop(dfs);
	solve(data, dfs);
}
