#include "minishell.h"


int                 main(int c, char **v, char **envp)
{
    char		*command;
	pid_t pid;

    command = ft_strnew(2048);
	while (ft_strncmp("exit\n", command, 5) != 0)
	{
		ft_putstr("$>");
		read(STDIN_FILENO, command, 2048);

 		char ***parsed = parse_command(str_till_bsn(command));
 		while (*parsed)
		{
 			if (parsed && *parsed && **parsed)
			{
 				if (!ft_strcmp("cd", **parsed))
				{
					write(1, "CD\n", 3);
 					cd_builtin(*parsed, envp);

				}
 				else
 					exe_process(parse_path(**parsed, envp), **parsed, *parsed, envp);
			}
			parsed++;
		}
	}
}