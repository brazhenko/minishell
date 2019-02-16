/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:35:09 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:35:11 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						*get_env(char *name, char **envp)
{
	int			i;
	char		**env;
	char		*envval;

	i = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], name, ft_strlen(name)) && ft_strlen(name))
		{
			env = ft_strsplit(envp[i], '=');
			free(env[0]);
			envval = env[1];
			free(env);
			return (envval);
		}
		i++;
	}
	return (NULL);
}
