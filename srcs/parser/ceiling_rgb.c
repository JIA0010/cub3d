/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:03 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/22 16:29:19 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

bool	ceiling_rgb(t_data *data)
{
	char	*all;
	int		i;

	all = data->parser->all;
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
	data->parser->ceiling_r = ft_atoi(str);
	free(str);
<<<<<<< HEAD
	// if (data->parser->ceiling_r < 0 && 255 < data->parser->ceiling_r)
	// 	return (false);
=======
	if (data->parser->ceiling_r < 0 || 255 < data->parser->ceiling_r)
		return (false);
>>>>>>> 85254ba25b4568af775a467ebff52d1426d242e9
	*index = j;
	return (true);
}

bool	ceiling_g(t_data *data, char *all, int *index)
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
	data->parser->ceiling_g = ft_atoi(str);
	free(str);
	if (data->parser->ceiling_g < 0 || 255 < data->parser->ceiling_g)
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
	data->parser->ceiling_b = ft_atoi(str);
	free(str);
	if (data->parser->ceiling_b < 0 || 255 < data->parser->ceiling_b)
		return (false);
	*index = j;
	return (true);
}
