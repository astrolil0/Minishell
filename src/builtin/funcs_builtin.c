#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\x1b[1m"
#define CYAN		"\033[0;36m"

void	run_echo(t_parse *data, int *i)
{
	int	x;
	int	j;

	x = *i;
	while (data->text[x])
	{
		j = 0;
		while (data->text[x][j])
			write(data->outfile, &data->text[x][j++], 1);
		if (data->text[x][j] == '\0' && data->text[x + 1] != NULL)
			write(data->outfile, " ", 1);
		x++;
		*i += 1;
	}
}

static int	all_n_chars(const char *str)//n var mı diye bakıyor ??
{
	while (*str != '\0')
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

void	exec_echo(t_parse *data, t_shell *m_shell)
{
	int	i;

	i = 0;
	if (!data->text)
		write(data->outfile, "\n", 1);
	else if (!data->text || data->text[0] == NULL || data->text[0][0] == '\0')
		write(data->outfile, "", 1);
	else
	{
		if (data->text[0][0] == '-' && data->text[0][1] == 'n'
			&& all_n_chars(data->text[0] + 2))
		{
			i = 1;
			if (data->text[1])
				run_echo(data, &i);
		}
		else
		{
			run_echo(data, &i);
			if (!data->text[i])
				write(data->outfile, "\n", 1);
		}
	}
	m_shell->exec_status = 0;
}

void	print_list(void *data)
{
	t_env	*new;
	char	*lost_key;

	new = (t_env *)data;
	if (!new->value)
		return ;
	lost_key = ft_strjoin(new->key, "=");
	if (lost_key)
	{
		printf("%s%-30s" COLOR_RESET, CYAN, lost_key);
		free(lost_key);
	}
	if (new->value)
		printf("\033[1;35m%s\033[0m\n", new->value);
}

void	exec_env(t_shell *m_shell)
{
	t_list	*lst;

	lst = m_shell->env;
	printf(COLOR_BOLD "%-30s%-18s\n" COLOR_RESET, "Name", "Value");
	while (lst != NULL)
	{
		print_list((void *)lst->content);
		lst = lst->next;
	}
	m_shell->exec_status = 0;
}
