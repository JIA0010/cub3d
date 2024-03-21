NAME		= cub3D
SRC_PATH	= srcs/
INIT_PATH	= srcs/init/
ERROR_PATH	= srcs/error/
PARSER_PATH	= srcs/parser/
PLAYER_PATH	= srcs/player/
RAY_PATH	= srcs/ray/
OBJ_PATH	= objs/
LIBFT_PATH	= Libft/
INCLUDES	= includes/
SRC_FILES	= main.c ft_free.c hook.c
INIT_FILES	= init.c init_parser.c init_player.c
ERROR_FILES	= error_arg.c check_error_arg.c error_all.c error_map.c error_floodfill.c
PARSER_FILES= parser.c all.c path.c floor_rgb.c ceiling_rgb.c map.c map_utils.c
PLAYER_FILES= player_pos.c move_player.c
RAY_FILES	= start_game.c utils.c ray_casting.c init_ray.c raycast_and_draw.c \
				texture.c init_player_dir.c get_wall_height.c start_dda.c draw_image_to_window.c rotate.c \
				free_data.c init_img.c
LIBFT_FILE	= libft.a
OBJ_FILES	= $(SRC_FILES:%.c=%.o) $(INIT_FILES:%.c=%.o) $(ERROR_FILES:%.c=%.o) \
				$(PARSER_FILES:%.c=%.o) $(PLAYER_FILES:%.c=%.o) $(RAY_FILES:%.c=%.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
INITS		= $(addprefix $(INIT_PATH), $(INIT_FILES))
ERRORS		= $(addprefix $(ERROR_PATH), $(ERROR_FILES))
PARSERS		= $(addprefix $(PARSER_PATH), $(PARSER_FILES))
PLAYERS		= $(addprefix $(PLAYER_PATH), $(PLAYER_FILES))
RAYS		= $(addprefix $(RAY_PATH), $(RAY_FILES))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
CFLAGS		= -Wall -Wextra -Werror
MLX			= $(MLX_OpenGL)
MLX_OpenGL	= -lmlx -framework OpenGL -framework AppKit
MLX_MMS		= -lm libmlx.dylib
ifdef MMS
	MLX		= $(MLX_MMS)
endif
ifdef DEBUG
	CFLAGS	+= -fsanitize=address -g
endif

##------------color-----------##
CHECK		= \033[36m[\033[0m✔\033[36m]\033[0m
REMOVE		= \033[38;5;211m[\033[0m✘\033[38;5;211m]\033[0m
GENERATE	= \033[38;5;227m[\033[0m➤\033[38;5;227m]\033[0m
BLUE		= \033[1;36m
YELLOW		= \033[38;5;227m
RED			= \033[38;5;211m
RESET		= \033[0m
##-----------------------------##

all:		$(NAME)

$(NAME):	$(OBJS)
	@ echo ""
	@ mkdir -p $(OBJ_PATH)
	@ $(MAKE) -C $(LIBFT_PATH)
	@ cp $(LIBFT) $(NAME)
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@ echo "$(CHECK) $(BLUE)finish Compiling $(NAME). $(RESET)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(INIT_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(ERROR_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(PARSER_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(PLAYER_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(RAY_PATH)%.c $(INCLUDES)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

clean:
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ $(RM) -r $(OBJ_PATH)
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files.$(RESET)\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ $(RM) $(NAME)
	@ $(RM) -r $(OBJ_PATH)
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files and $(NAME).$(RESET)\n"

re:			fclean all

debug:		fclean
	@ make DEBUG=1

42:			fclean
	@ make MMS=1m

.PHONY:		all clean fclean re debug
