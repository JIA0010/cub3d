# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 13:32:56 by cjia              #+#    #+#              #
#    Updated: 2023/08/28 14:49:20 by cjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCSDIR = src/

LIBFT	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
PRINTF = ft_printf.c ft_printf_hex.c ft_printf_p.c ft_printf_i.c ft_printf_c.c ft_printf_s.c ft_printf_u.c
GNL = get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(SRCSDIR), $(LIBFT:.c=.o))
OBJS += $(addprefix $(SRCSDIR), $(PRINTF:.c=.o))
OBJS += $(addprefix $(SRCSDIR), $(GNL:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME):$(OBJS)
		ar crs $(NAME) $(OBJS)

all:$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all



# NAME = libft.a
# SOURCE =ft_strlen.c \
# 		ft_strlcpy.c \
# 		ft_strlcat.c \
# 		ft_strchr.c \
# 		ft_strrchr.c \
# 		ft_strnstr.c \
# 		ft_strncmp.c \
# 		ft_memset.c \
# 		ft_bzero.c \
# 		ft_memcpy.c \
# 		ft_memchr.c \
# 		ft_memmove.c \
# 		ft_memcmp.c \
# 		ft_atoi.c \
# 		ft_isalpha.c \
# 		ft_isdigit.c \
# 		ft_isalnum.c \
# 		ft_isascii.c \
# 		ft_isprint.c \
# 		ft_toupper.c \
# 		ft_tolower.c \
# 		ft_calloc.c \
# 		ft_strdup.c \
# 		ft_substr.c \
# 		ft_strjoin.c \
# 		ft_strtrim.c \
# 		ft_itoa.c \
# 		ft_split.c\
# 		ft_strmapi.c \
# 		ft_striteri.c\
# 		ft_putchar_fd.c \
# 		ft_putstr_fd.c \
# 		ft_putendl_fd.c \
# 		ft_putnbr_fd.c

# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# OBJS = $(SOURCE:%.c=%.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

# # $(OBJS): $(SOURCE)
# # 	$(CC) $(CFLAGS) -c $(SOURCE)	

# clean:
# 	rm -rf $(OBJS)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

# .PHONY:	all clean fclean re
