#include "../minishell.h"
#include <stdlib.h>
void	str_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	get_them(t_shell **shell)
{
	char *user;
	// char *pwd;
	// char *title;
	// char *temp;

	user = get_env((*shell)->env,"USER");
}
void	env_get(char **env, t_shell **shell)
{
	t_env	*x;
	char **str;

	free((*shell)->env);
	(*shell)->env = NULL;
	while(*env)
	{
		x = malloc(sizeof(t_env));
		str = ft_split(*env,'=');
		if (str && str[0] && str[1])
		{
			x->name = ft_strdup(str[0]);
			x->value = ft_strdup(str[1]);
			ft_lstadd_back(&(*shell)->env, ft_lstnew(x));
		}
		str_free(str);
		env++;
	}
}