/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:03 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/24 16:38:03 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

bool	floor_rgb(t_data *data)
{
	char	*all;
	int		i;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && all[i] != 'F')
		i++;
	if (all[i] == 'F')
		i++;
	if (all[i] == '\0')
		return (false);
	if (floor_r(data, all, &i) == false)
		return (false);
	if (floor_g(data, all, &i) == false)
		return (false);
	if (floor_b(data, all, &i) == false)
		return (false);
	return (true);
}

bool	floor_r(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && ft_isalnum(all[i]) == false)
		i++;
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	if (ft_strlen(str) > 3)
		return (false);
	data->map->floor_r = ft_atoi(str);
	free(str);
	if (data->map->floor_r < 0 || 255 < data->map->floor_r)
		return (false);
	*index = j;
	return (true);
}

bool	floor_g(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && ft_isalnum(all[i]) == false)
		i++;
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	if (ft_strlen(str) > 3)
		return (false);
	data->map->floor_g = ft_atoi(str);
	free(str);
	if (data->map->floor_g < 0 || 255 < data->map->floor_g)
		return (false);
	*index = j;
	return (true);
}

bool	floor_b(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && ft_isalnum(all[i]) == false)
		i++;
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	if (ft_strlen(str) > 3)
		return (false);
	data->map->floor_b = ft_atoi(str);
	free(str);
	if (data->map->floor_b < 0 || 255 < data->map->floor_b)
		return (false);
	*index = j;
	return (true);
}
