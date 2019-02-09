#include "minishell.h"


int                 main(int c, char **v, char **envp)
{
    char		*command;

    command = ft_strnew(2048);
	pid_t pid;
    char *const parmList[] = {"/bin/ls", "-l", NULL};
    char *const envParms[2] = {NULL};



//		puts(get_env(ft_strjoin("PATH", "="), envp));
	// exe_process()

	while (ft_strncmp("exit\n", command, 5) != 0)
	{
		ft_putstr("$>");
		read(STDIN_FILENO, command, 2048);

 		char ***parsed = parse_command(str_till_bsn(command));
 		while (*parsed)
		{
 			if (parsed && *parsed && **parsed)
				exe_process(parse_path(**parsed, envp), **parsed, *parsed, envp);
 			parsed++;
		}
	}
}