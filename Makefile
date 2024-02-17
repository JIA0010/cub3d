NAME		= cub3d
SRC_PATH	= srcs/
INIT_PATH	= srcs/init/
ERROR_PATH	= srcs/error/
PARSER_PATH	= srcs/parser/
RAY_PATH	= srcs/ray/
OBJ_PATH	= objs/
LIBFT_PATH	= Libft/
INCLUDES	= includes/
SRC_FILES	= main.c
INIT_FILES	= init.c init_parser.c
ERROR_FILES	= error_init.c
PARSER_FILES= parser.c
RAY_FILES	= 
LIBFT_FILE	= libft.a
OBJ_FILES	= $(SRC_FILES:%.c=%.o) $(INIT_FILES:%.c=%.o) $(ERROR_FILES:%.c=%.o) \
				$(PARSER_FILES:%.c=%.o) $(RAY_FILES:%.c=%.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
INITS		= $(addprefix $(INIT_PATH), $(INIT_FILES))
ERRORS		= $(addprefix $(ERROR_PATH), $(ERROR_FILES))
PARSERS		= $(addprefix $(PARSER_PATH), $(PARSER_FILES))
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
	@ mkdir -p ./objs/
	@ $(MAKE) -C $(LIBFT_PATH)
	@ cp $(LIBFT) $(NAME)
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(CHECK) $(BLUE)finish Compiling minishell. $(RESET)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c $(INCLUDES)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(INIT_PATH)%.c $(INCLUDES)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(ERROR_PATH)%.c $(INCLUDES)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(PARSER_PATH)%.c $(INCLUDES)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

$(OBJ_PATH)%.o:$(RAY_PATH)%.c $(INCLUDES)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

clean:
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ $(RM) -r ./objs/
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files.$(RESET)\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ $(RM) $(NAME)
	@ $(RM) -r ./objs/
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files and $(NAME).$(RESET)\n"

re:			fclean all

debug:
	@ make DEBUG=1

.PHONY:		all clean fclean re