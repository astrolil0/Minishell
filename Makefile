NAME	:= minishell
CC		:= gcc 
INCLUDE	:= ./includes
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror -g

SRCDIR	:= src
SRC		:=src/main/env.c \
			src/main/main.c \
			src/signal/signal.c \
			src/expander/expander_utils.c 
OBJDIR	:= ./objectives
OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline -o $@
	@echo "Done!"
	@echo "$(COLOR_LBLUE)"
	@echo "		==================================================================="
	@echo "		███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "		████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "		██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "		██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "		██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "		╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
	@echo "		==================================================================="

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	@echo "Cleaning..."
	@make fclean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re