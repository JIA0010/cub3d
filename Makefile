NAME		= cub3d
SRC_PATH	= srcs/
PARSER_PATH	= parser/
RAY_PATH	= ray/
OBJ_PATH	= objs/
INCLUDES	= includes/
SRC_FILES	= main.c
PARSER_FILES= 
RAY_FILES	= 
OBJ_FILES	= $(SRC_FILES:%.c=%.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
PARSERS		= $(addprefix $(SRC_PATH), $(PARSER_PATH), $(PARSER_FILES))
RAYS		= $(addprefix $(SRC_PATH), $(RAY_PATH), $(RAY_FILES))
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
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@ echo "$(CHECK) $(BLUE)finish Compiling minishell. $(RESET)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c $(INCLUDES)
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
	@ $(RM) -r ./objs/
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r ./objs/
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files and $(NAME).$(RESET)\n"

re:			fclean all

debug:
	@ make DEBUG=1

.PHONY:		all clean fclean re