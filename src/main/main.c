#include "../minishell.h"
#include <stdlib.h>
#include <unistd.h>
void	initilaze(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	(*shell)->env = malloc(sizeof(t_env));
}

void	just_read(t_shell *shell)
{
	
}

int main(int ac, char **av, char **env)
{
    t_shell *shell;

	(void)av;
	if(ac != 1)
		exit(ft_eror(1, "this is the error message!"));
	initilaze(&shell);
	env_get(env,&shell);
	signals_control();
	while(1)
	{
		just_read(shell);
	}
}


int ft_eror(int finish, char *eror)
{
	write(1, eror, ft_strlen(eror));
	write(1, "\n", 1);
	return(finish); 
}