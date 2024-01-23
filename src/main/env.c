#include "../includes/minishell.h"
#include <stdlib.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	env_get(char **env, t_shell **shell)
{
	t_env	*node;
	char	**str;

	free((*shell)->env);
	(*shell)->env = NULL;
	while (*env)
	{
		node = malloc(sizeof(t_env));
		if (!node)
			return ;
		str = ft_split(*env, '=');
		if (str && str[0] && str[1])
		{
			node->key = ft_strdup(str[0]);
			node->value = ft_strdup(str[1]);
			ft_lstadd_back(&(*shell)->env, ft_lstnew(node));
		}
		free_str(str);
		env++;
	}
}

void	begin_shell_free(t_shell *t_shell, int count)
{
	if (count == 1)
		free(t_shell);
	if (count == 2)
	{
		free (t_shell->env);
		free (t_shell);
	}
}

void	error_free(t_list **node)
{
	if (!*node)
		return ;
	if ((*node)->next != NULL)
		free_node((*node)->next);
	if ((*node)->content)
		(*node)->content = (free((*node)->content), NULL);
	if ((*node))
		(*node) = (free(*node), NULL);
}
