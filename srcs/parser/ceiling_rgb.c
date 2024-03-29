/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraiyuina <hiraiyuina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:03 by yhirai            #+#    #+#             */
/*   Updated: 2024/03/21 19:19:28 by hiraiyuina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

bool	ceiling_rgb(t_data *data)
{
	char	*all;
	int		i;

	all = data->map->all;
	i = 0;
	while (all[i] != '\0' && all[i] != 'C')
		i++;
	if (all[i] == 'C')
		i++;
	if (all[i] == '\0')
		return (false);
	if (ceiling_r(data, all, &i) == false)
		return (false);
	if (ceiling_g(data, all, &i) == false)
		return (false);
	if (ceiling_b(data, all, &i) == false)
		return (false);
	return (true);
}

bool	ceiling_r(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && all[i] != '\n' && ft_isalnum(all[i]) == false)
		i++;
	if (all[i] == '\0' || all[i] == '\n')
		return (false);
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	data->map->ceiling_r = ft_atoi(str);
	free(str);
	if (data->map->ceiling_r < 0 || 255 < data->map->ceiling_r)
		return (false);
	*index = j;
	return (true);
}

bool	ceiling_g(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && all[i] != '\n' && ft_isalnum(all[i]) == false)
		i++;
	if (all[i] == '\0' || all[i] == '\n')
		return (false);
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	data->map->ceiling_g = ft_atoi(str);
	free(str);
	if (data->map->ceiling_g < 0 || 255 < data->map->ceiling_g)
		return (false);
	*index = j;
	return (true);
}

bool	ceiling_b(t_data *data, char *all, int *index)
{
	char	*str;
	int		i;
	int		j;

	i = *index;
	while (all[i] != '\0' && all[i] != '\n' && ft_isalnum(all[i]) == false)
		i++;
	if (all[i] == '\0' || all[i] == '\n')
		return (false);
	j = i;
	while (ft_isalnum(all[j]) == true)
		j++;
	str = ft_substr(all, i, j - i);
	if (str == NULL)
		return (false);
	data->map->ceiling_b = ft_atoi(str);
	free(str);
	if (data->map->ceiling_b < 0 || 255 < data->map->ceiling_b)
		return (false);
	*index = j;
	return (true);
}
