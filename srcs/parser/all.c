/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhirai <yhirai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:00:09 by yhirai            #+#    #+#             */
/*   Updated: 2024/02/21 11:35:04 by yhirai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static char	*ft_strjoin_c(char const *s1, char const *s2);

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
