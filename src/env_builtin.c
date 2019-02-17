/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:37:56 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:37:57 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				delete_env(char **envp_cpy)
{
	int 	i;

	i = 0;
	while (envp_cpy[i])
	{
		free(envp_cpy[i]);
		i++;
	}
	free(envp_cpy);
}

char 				**envp_cpy(char **envp)
{
	int 		envpc;
	int 		i;
	char 		**envp_cpy;

	envpc = 0;
	i = 0;
	while (envp[envpc])
		envpc++;
	envp_cpy = (char **)malloc(sizeof(char *) * (envpc + 1));
	envp_cpy[envpc] = NULL;
	while (envp[i])
	{
		envp_cpy[i] = ft_strnew(ft_strlen(envp[i]));
		ft_strcpy(envp_cpy[i], envp[i]);
		i++;
	}
	return (envp_cpy);
}

void				setenv_builtin()
{

}

void				unsetenv_builtin()
{

}

void				env_builtin(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl(envp[i]);
		i++;
	}
}
