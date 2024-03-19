/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:25:22 by yoshimurahi       #+#    #+#             */
/*   Updated: 2024/03/19 15:10:23 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/define_ray.h"
#include "../includes/player.h"

int	key_hook_esc(t_data *data)
{
	clean_exit(data->ray, 0);
	return (0);
}
