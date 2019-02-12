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
#include ".shell_config.h"

int						main(int c, char **v, char **envp)
{
	char		***parsed;

	while (1)
	{

		parsed = prompt(v, envp);
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
//		/* delete_parsed (parsed) */
	}
}
