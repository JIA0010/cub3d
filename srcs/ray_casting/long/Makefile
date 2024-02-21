# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 14:51:35 by cjia              #+#    #+#              #
#    Updated: 2023/09/21 15:39:43 by cjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC_SDIR	= src/
SRCS = main.c create_map.c error.c check_map.c hook.c about_player.c map_search_all.c import_map.c
OBJS	= $(addprefix $(SRC_SDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
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
	$(CC) $(CFLAGS) -lmlx $(FRAMEWORK_FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft #-L$(MLX_DIR) -lmlx $(MLXFRAGS)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)


$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
