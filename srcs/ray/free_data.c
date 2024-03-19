/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:41:39 by cjia              #+#    #+#             */
/*   Updated: 2024/03/19 15:18:20 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/define_ray.h"

int	free_data(t_ray *data)
{
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	free(data->rgb_ceiling);
	free(data->rgb_floor);
	return (FAILURE);
}

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
