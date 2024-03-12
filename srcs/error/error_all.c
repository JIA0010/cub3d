/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:24:22 by hiraiyuina        #+#    #+#             */
/*   Updated: 2024/03/12 16:04:18 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

static bool	check_path_rgb(char *all, size_t *index);
static void	skip_map(t_data *data, char *all, size_t *index);

bool	error_all(t_data *data)
{
	char	*all;
	size_t	i;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0')
	{
		skip_map(data, all, &i);
		if (check_path_rgb(all, &i) == false)
			return (false);
		else if (all[i] != '\0' && all[i] != '1' && all[i] != '0'
			&& all[i] != 'N' && all[i] != 'S' && all[i] != 'E'
			&& all[i] != 'W' && all[i] != ' ' && all[i] != '	'
			&& all[i] != '\n' && all[i] != 'F' && all[i] != 'C')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_path_rgb(char *all, size_t *index)
{
	size_t	i;

	i = *index;
	if (all[i] == '\0')
		return (true);
	if (all[i] == 'N' || all[i] == 'S' || all[i] == 'W' || all[i] == 'E'
		|| all[i] == 'F' || all[i] == 'C')
	{
		if (!((all[i + 1] != '\0' && all[i + 2] != '\0')
				&& ((all[i] == 'N' && all[i + 1] == 'O' && all[i + 2] == ' ')
					|| (all[i] == 'S' && all[i + 1] == 'O' && all[i + 2] == ' ')
					|| (all[i] == 'W' && all[i + 1] == 'E' && all[i + 2] == ' ')
					|| (all[i] == 'E' && all[i + 1] == 'A' && all[i + 2] == ' ')
					|| (all[i] == 'F' && all[i + 1] == ' ')
					|| (all[i] == 'C' && all[i + 1] == ' '))))
			return (false);
		while (all[i] != '\0' && all[i] != '\n')
			i++;
	}
	*index = i;
	return (true);
}

static void	skip_map(t_data *data, char *all, size_t *index)
{
	size_t	i;
	size_t	x;
	size_t	z;

	i = *index;
	z = 0;
	while (1)
	{
		x = 0;
		if (data->map->map[x][z] == '\0')
			break ;
		while (data->map->map[x] != NULL && all[i] != '\n')
		{
			if (data->map->map[x][z] != all[i])
				return ;
			i++;
			x++;
		}
		if (all[i] == '\n')
			i++;
		z++;
	}
	*index = i - 1;
}
