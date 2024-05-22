/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erhorasa  <erhorasa@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:57:28 by erhorasa          #+#    #+#             */
/*   Updated: 2024/01/15 13:06:58 by erhorasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

void	_free_env(t_list *tmp2, t_shell *m_shell)
{
	t_env	*tmp;

	while (tmp2)
	{
		tmp = tmp2->content;
		if (tmp2->content)
		{
			if (tmp->key)
				free(tmp->key);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
		}
		tmp2 = tmp2->next;
	}
	while (m_shell->env)
	{
		tmp2 = m_shell->env;
		m_shell->env = m_shell->env->next;
		if (tmp2)
			free(tmp2);
	}
}

void	free_env(t_shell *m_shell)
{
	t_list	*tmp2;

	tmp2 = m_shell->env;
	if (tmp2 && tmp2->content)
		_free_env(tmp2, m_shell);
	else if (m_shell->env && !m_shell->env->content)
		free(m_shell->env);
}

void	free_(t_shell *m_shell)
{
	free_env(m_shell);
	clear_history();
}

void	free_loop(int control, t_shell *m_shell)
{
	if (m_shell->cmd)
		free(m_shell->cmd);
	if (control)
	{
		if (m_shell->parse)
			free_parser(m_shell);
	}
	if (m_shell->heredoc)
	{
		free(m_shell->heredoc);
		m_shell->heredoc = NULL;
	}
}

void	execve_child_free(char **str, t_shell *m_shell)
{
	free_(m_shell);
	free_loop(1, m_shell);
	free_text(str);
	free(m_shell->lex_list);
	free(m_shell);
}
