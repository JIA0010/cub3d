NAME		= libft.a
OBJ_PATH	= objs/
INCLUDES	= libft.h
SRC_FILES	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ_FILES	= $(SRC_FILES:%.c=%.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
CFLAGS		= -Wall -Wextra -Werror

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
	@ ar rc $(NAME) $(OBJS)
	@ echo "$(CHECK) $(BLUE)finish Compiling minishell. $(RESET)"

$(OBJ_PATH)%.o:%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

clean:
	@ $(RM) -r $(OBJ_PATH)
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r $(OBJ_PATH)
	@ printf "$(REMOVE) $(RED)$(NAME) : Remove object files and $(NAME).$(RESET)\n"

re:			fclean all

debug:
	@ make DEBUG=1

.PHONY:		all clean fclean re