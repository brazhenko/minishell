/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:27:03 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:27:04 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						main(int c, char **v, char **envp)
{
	char		*command;
	char		***parsed;

	command = ft_strnew(2048);
	while (1)
	{
		ft_putstr(getcwd(NULL, 1));
		ft_putstr("  $> ");
		read(STDIN_FILENO, command, 2048);
		parsed = parse_command(str_till_bsn(command), envp);
		while (*parsed)
		{
			if (parsed && *parsed && **parsed)
			{
				if (ft_strequ("echo", **parsed))
					echo_builtin(*parsed, envp);
				else if (ft_strequ("cd", **parsed))
					cd_builtin(*parsed, envp);
				else if (ft_strequ("setenv", **parsed))
					(setenv((*parsed)[1], (*parsed)[2], 1));
				else if (ft_strequ("unsetenv", **parsed))
					;
				else if (ft_strequ("env", **parsed))
					env_builtin(envp);
				else if (ft_strequ("exit", **parsed))
					exit(0);
				else
				{
					exe_process(parse_path(**parsed, envp),
									**parsed, *parsed, envp);
				}
			}
			parsed++;
		}
	}
}
