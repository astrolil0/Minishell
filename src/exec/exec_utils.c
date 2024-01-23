#include "../../includes/minishell.h"

t_parse	*_next_command(t_parse **parse)
{
	if ((*parse)->infile > STDERR || (*parse)->outfile > STDERR
		|| (*parse)->type == HEREDOC)
	{
		return ((*parse)->next->next);
	}
	else
	{
		return ((*parse)->next);
	}
}

int	single_or_multi_command(t_shell *m_shell)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = m_shell->parse;
	while (parse)
	{
		if (parse->type == PIPE)
			i++;
		parse = parse->next;
	}
	return (i);
}
