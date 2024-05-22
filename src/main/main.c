/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erhorasa <erhorasa@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:57:28 by erhorasa          #+#    #+#             */
/*   Updated: 2024/01/23 13:21:11 by erhorasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

int		g_does_have_heredoc;

void	get_read(t_shell *shell)
{
	shell->cmd = readline("\033[1;31mMyShell\033[0m:");
	if (shell->cmd && !is_space(shell->cmd))
	{
		free(shell->cmd);
		get_read(shell);
	}
	else if (!shell->cmd)
	{
		free_loop(0, shell);
		free_(shell);
		free(shell->lex_list);
		free(shell);
		exit(1);
	}
	add_history(shell->cmd);
}

int	shell_init(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	if (!*shell)
		return (0);
	(*shell)->env = malloc(sizeof(t_env));
	if (!(*shell)->env)
	{
		begin_shell_free(*shell, 1);
		return (0);
	}
	(*shell)->lex_list = malloc(sizeof(t_lexer));
	if (!(*shell)->lex_list)
	{
		begin_shell_free(*shell, 2);
		return (0);
	}
	(*shell)->lex_list->lex = NULL;
	(*shell)->exec_status = 0;
	(*shell)->heredoc = NULL;
	(*shell)->cmd = NULL;
	g_does_have_heredoc = 0;
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;
	int		control;

	(void)av;
	control = 0;
	if (ac != 1)
		exit(write(2, "This program cannot accept any arguments\n", 41));
	shell_init(&shell);
	env_get(env, &shell);
	signals_control();
	while (1)
	{
		get_read(shell);
		if (quote_check(shell->cmd))
		{
			lexer(shell);
			expander(shell);
			parser(shell, env, control);
		}
		else
		{
			free(shell->cmd);
			continue ;
		}
	}
}
