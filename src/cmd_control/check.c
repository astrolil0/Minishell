/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erhorasa <erhorasa@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:57:28 by erhorasa          #+#    #+#             */
/*   Updated: 2024/01/15 16:26:37 by erhorasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	is_valid_other(char *a, char *b)
{
	if ((a[0] == '<' && !a[1]) && !b)
		return (0);
	else if ((a[0] == '>' && !a[1]) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && !a[1])) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] == '<')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '>' && a[1] == '>')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] != '<')) && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] != '>') && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if (((a[0] == '<' && a[1] == '<')) && (b[0] == '>' || b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] == '>') && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if ((a[0] == '|' && !a[1] && b[0] == '|' && !b[1]))
		return (0);
	return (1);
}

int	cmd_is_valid(t_lexer *lex_list, char *a, char *b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lex_list->lex;
	while (tmp)
	{
		a = tmp->content;
		if (tmp->next)
			b = tmp->next->content;
		if (i == 0 && !b && ((a[0] == '<') || (a[0] == '>')))
			return (print_error());
		if ((a[0] == '|' && !a[1]) && i == 0)
			return (print_error());
		else if ((a[0] == '>' && !a[1]) && !b)
			return (print_error());
		else if (!is_valid_other(a, b))
			return (print_error());
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	quote_len1(char *data)
{
	int	j;
	int	i;
	int	quote_axis;

	i = -1;
	j = 0;
	while (data[++i])
	{
		if (data[i] == '\"' || data[i] == '\'')
		{
			j++;
			quote_axis = data[i++];
			while (data[i] && data[i] != quote_axis)
				i++;
			if (!data[i])
				break ;
			j++;
		}
	}
	return (j);
}

int	quote_check(char *data)
{
	int	i;

	i = 0;
	i = quote_len1(data);
	if (i % 2 != 0)
	{
		printf("minishell: quote error\n");
		return (0);
	}
	return (1);
}

int	cmd_control(t_shell *shell)
{
	return (cmd_is_valid(shell->lex_list, NULL, NULL));
}
