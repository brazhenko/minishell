#include "minishell.h"
#include ".shell_config.h"

char	 		***prompt(char **v, char **envp)
{
	char *command = ft_strnew(2048);

	ft_putstr(PROMPT_COLOR);
	ft_putstr("➜ ");
	ft_putstr(PWD_COLOR);
	ft_putstr(getcwd(NULL, 1));
	ft_putstr(CROSS_COLOR);
	ft_putstr(" ✗ ");
	ft_putstr(COMMAND_COLOR);
	read(STDIN_FILENO, command, 2048);
	ft_putstr(DEFAULT_COLOR);
	return (parse_command(str_till_bsn(command), envp));
}
