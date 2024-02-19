/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:30:17 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 16:51:17 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

bool	check_error_arg(int argc, char **argv)
{
	if (argc != 2)
		return (error_argc());
	if (check_argv(argv) == false)
		return (error_argv());
	return (true);
}

bool	check_argv(char **argv)
{
	int		fd;
	size_t	len;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'c' ||
		argv[1][len - 2] != 'u' || argv[1][len - 1] != 'b')
		return (false);
	return (true);
}
