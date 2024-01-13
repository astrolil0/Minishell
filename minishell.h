#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# define EXEC 0
# define HEREDOC 1
# define PIPE 2
# define GREAT 3
# define GREATER 4
# define LESS 5
# define STDINN 0
# define STDOUT 1
# define STDERR 2
typedef struct s_env
{
    char *name;
    char *value;
}               t_env;

typedef struct s_data
{
    char *read_data;
}               t_data;

typedef struct s_lexer
{
    t_list  *lex;
}               t_lexer;

typedef struct s_parse
{
    struct s_parse  *next;
}               t_parse;

typedef struct s_shell
{
    t_list      *env;
    t_lexer     *lex_list;
    t_parse     *parse;
    char        *cmd;
}               t_shell;

/**
 * Lexer Functions
 */

/**
 * Expander Functions
 */

char    *get_env(t_list *env, char *key);

/**
 * Parser Functions
 */

/**
 * Execute Functions
 */

/**
 * Builtins Functions
 */

/**
 * Signals Functions
 */
void	signals(int sig);
void	signal_control(void);

/**
 * Main Folder Functions
 */
void	env_get(char **env, t_shell **shell);
void	str_free(char **str);
void	initilaze(t_shell **shell);
int     ft_eror(int finish, char **eror);

/**
 * Heredoc Folder Functions
 */

/**
 * Create Dup Folder Functions
 */

/**
 * Check Folder Functions
 */

/**
 * Utils Folder Functions
 */

/**
 * Create Files Folder Functions
 */
#endif