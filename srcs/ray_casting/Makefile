# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 14:51:35 by cjia              #+#    #+#              #
#    Updated: 2024/02/21 13:50:37 by cjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pre_ray_casting

SRC_SDIR	= pre_src/
SRCS = pre_main.c import.c utils.c
OBJS	= $(addprefix $(SRC_SDIR),  $(SRCS:.c=.o))

CC		= cc
# CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
MLXFRAGS = -lX11 -lXext -lm
FRAMEWORK_FLAGS = -framework OpenGL -framework AppKit

LIBFT_DIR	= libft/
LIBFT_NAME	= libft.a
MLX_DIR		= minilibx/
MLX_NAME		= libmlx.a

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC)  -lmlx $(FRAMEWORK_FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft #-L$(MLX_DIR) -lmlx $(MLXFRAGS)

.c.o:
	$(CC) -Imlx -c $< -o $(<:.c=.o)


$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
