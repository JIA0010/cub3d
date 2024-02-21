NAME		= cub3d
SRC_PATH	= srcs/
INIT_PATH	= srcs/init/
ERROR_PATH	= srcs/error/
PARSER_PATH	= srcs/parser/
PLAYER_PATH	= srcs/player/
RAY_PATH	= srcs/ray/
OBJ_PATH	= objs/
LIBFT_PATH	= Libft/
INCLUDES	= includes/
SRC_FILES	= main.c ft_free.c
INIT_FILES	= init.c init_parser.c init_player.c
ERROR_FILES	= error_init.c error_arg.c check_error_arg.c error_parser.c \
				error_map.c error_map_floodfill.c
PARSER_FILES= parser.c all.c path.c floor_rgb.c ceiling_rgb.c map.c map_utils.c \
				player_pos.c
PLAYER_FILES= player_pos.c
RAY_FILES	= 
LIBFT_FILE	= libft.a
OBJ_FILES	= $(SRC_FILES:%.c=%.o) $(INIT_FILES:%.c=%.o) $(ERROR_FILES:%.c=%.o) \
				$(PARSER_FILES:%.c=%.o) $(RAY_FILES:%.c=%.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
INITS		= $(addprefix $(INIT_PATH), $(INIT_FILES))
ERRORS		= $(addprefix $(ERROR_PATH), $(ERROR_FILES))
PARSERS		= $(addprefix $(PARSER_PATH), $(PARSER_FILES))
PLAYERS		= $(addprefix $(PLAYER_PATH), $(PLAYER_FILES))
RAYS		= $(addprefix $(RAY_PATH), $(RAY_FILES))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
CFLAGS		= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
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
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@ echo "$(CHECK) $(BLUE)finish Compiling minishell. $(RESET)"

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

.PHONY:		all clean fclean re debug