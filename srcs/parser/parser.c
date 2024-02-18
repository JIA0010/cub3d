/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:09 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/18 19:20:33 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/error.h"
#include "../../includes/init.h"

static char	*ft_strjoin_c(char const *s1, char const *s2);

bool	parser(t_data *data, char *file)
{
	if (init_parser(data) == false)
		return (error_init_parser());
	if (all(data, file) == false)
		return (error_parser_all());
	if (path(data) == false)
		return (error_parser_path());
	if (floor_rgb(data) == false)
		return (false);
	if (ceiling_rgb(data) == false)
		return (false);
	if (map(data) == false)
		return (false);
	printf("-----all-----\n%s\n-------------\n", data->parser->all);
	printf("path_north[%s]\n", data->parser->path_north);
	printf("path_south[%s]\n", data->parser->path_south);
	printf("path_west[%s]\n", data->parser->path_west);
	printf("path_east[%s]\n", data->parser->path_east);
	printf("floor_rgb[%d,%d,%d]\n", data->parser->floor_r,
		data->parser->floor_g, data->parser->floor_b);
	printf("ceiling_rgb[%d,%d,%d]\n", data->parser->ceiling_r,
		data->parser->ceiling_g, data->parser->ceiling_b);
	return (true);
}

bool	all(t_data *data, char *file)
{
	char	str[2];
	size_t	read_size;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	data->parser->all = NULL;
	while (1)
	{
		read_size = read (fd, &str, 1);
		if (read_size == 0)
			break ;
		if (read_size < 0)
			return (false);
		tmp = data->parser->all;
		data->parser->all = ft_strjoin_c(tmp, str);
		if (data->parser->all == NULL)
			return (false);
		free(tmp);
	}
	close(fd);
	return (true);
}

static char	*ft_strjoin_c(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
