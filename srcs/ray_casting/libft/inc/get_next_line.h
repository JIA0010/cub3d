/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:04:37 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:51:27 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buf);
char	*return_line(char *buf);
char	*save_str(char *buf);
void	*ft_calloc(size_t n, size_t size);

#endif