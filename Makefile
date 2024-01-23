NAME	:= minishell
CC		:= gcc 
INCLUDE	:= ./includes
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror -g

SRCDIR	:= src
SRC		:= src/builtin/builtin.c \
			src/builtin/funcs_builtin.c \
			src/builtin/funcs_builtin1.c \
			src/builtin/funcs_builtin2.c \
			src/builtin/funcs_builtin3.c \
			src/builtin/funcs_builtin4.c \
			src/cmd_control/check.c \
			src/cmd_control/check_utils.c \
			src/dup2/fd_dup2.c \
			src/exec/exec_free.c \
			src/exec/exec_free2.c \
			src/exec/exec.c \
			src/exec/run_execve.c \
			src/exec/run_execve1.c \
			src/expander/expander.c \
			src/files/create_files_utils.c \
			src/files/create_files.c \
			src/heredoc/heredoc_utils.c \
			src/heredoc/heredoc.c \
			src/lexer/lexer.c \
			src/main/env.c \
			src/main/main.c \
			src/parser/parser.c \
			src/parser/parser_utils.c \
			src/signal/signal.c \
			src/expander/expander_utils.c \
			src/utils/utils.c \
			src/exec/exec_utils.c 

OBJDIR	:= ./objectives
OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline -o $@
	@echo "\033[32mCompilation succeeded!\033[0m"
	@echo "\033[1;31m\t\t███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\033[0m"
	@echo "\033[1;32m\t\t████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\033[0m"
	@echo "\033[1;33m\t\t██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\033[0m"
	@echo "\033[1;34m\t\t██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\033[0m"
	@echo "\033[1;35m\t\t██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\033[0m"
	@echo "\033[1;36m\t\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\033[0m"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;31mCleaning...\033[0m"
	@make clean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	@echo "\033[1;31mCleaning...\033[0m"
	@make fclean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re