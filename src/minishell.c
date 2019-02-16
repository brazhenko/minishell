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
	int			i;
	i = 0;

	while (1)
	{
		parsed = prompt(v, envp);
		while (parsed[i])
		{
			if (parsed && parsed[i] && parsed[i][0])
			{
				if (ft_strequ("echo", parsed[i][0]))
					echo_builtin(parsed[i], envp);
				else if (ft_strequ("cd", parsed[i][0]))
					cd_builtin(parsed[i], envp);
				else if (ft_strequ("setenv", parsed[i][0]))
					;
				else if (ft_strequ("unsetenv", parsed[i][0]))
					;
				else if (ft_strequ("env", parsed[i][0]))
					env_builtin(envp);
				else if (ft_strequ("exit", parsed[i][0]))
				{
					delete_commandvv(parsed);
					exit(0);
				}
				else
				{
					execute_process(parse_path(parsed[i][0], envp),
									parsed[i][0], parsed[i], envp);
				}
			}
			i++;
		}
		i = 0;
		delete_commandvv(parsed);
	}
}
