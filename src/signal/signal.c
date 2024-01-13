#include "../includes/minishell.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>


void	signals(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	//rl_replace_line("", 0);
	rl_redisplay();
}
void	signals_control(void)
{
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
}