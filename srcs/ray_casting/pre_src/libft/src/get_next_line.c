/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:10:15 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:14:53 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*save_str(char *buf)
{
	int		i;
	int		j;
	char	*buf_str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	buf_str = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	if (!buf_str)
	{
		free(buf);
		return (NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		buf_str[j++] = buf[i++];
	buf_str[j] = '\0';
	free(buf);
	return (buf_str);
}

char	*return_line(char *buf)
{
	int		i;
	char	*output_line;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	output_line = ft_calloc(i + 2, sizeof(char));
	if (!output_line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		output_line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		output_line[i] = buf[i];
		i++;
	}
	output_line[i] = '\0';
	return (output_line);
}

char	*read_line(int fd, char *buf)
{
	char	*tem_str;
	int		byteread;

	byteread = 1;
	tem_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tem_str)
		return (NULL);
	while (byteread != 0 && !ft_strchr(tem_str, '\n'))
	{
		byteread = read(fd, tem_str, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(tem_str);
			return (NULL);
		}
		tem_str[byteread] = '\0';
		buf = ft_strjoin(buf, tem_str);
	}
	free(tem_str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
		return (NULL);
	line = return_line(buf);
	if (!line)
		return (NULL);
	if (line && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	buf = save_str(buf);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		n;

// 	n = 1;
// 	fd = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("file can't open");
// 		return (-1);
// 	}
// 	while (n < 10)
// 	{
// 		line = get_next_line(fd);
// 		printf("line [%02d]: %s\n", n, line);
// 		free(line);
// 		n++;
// 	}
// 	close(fd);
// 	return (0);
// }

// #include <libc.h>

// __attribute__((destructor)) void destructor()
// {
// 	system("leaks -q a.out");
// }