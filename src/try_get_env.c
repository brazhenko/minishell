/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_get_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:31:26 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:31:28 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * 		Parses system char** envp copy and returns a
 * 		new char* if an env var is found
 * 		or the old param instead.
 */

char					*try_get_env(char *str, char **envp)
{
	char	*env_var;

	env_var = get_env(str + 1, envp);
	if (str && *str == '$')
		return (env_var ? env_var : "");
	else if (ft_strequ("~", str))
		return (try_get_env("$HOME", envp));
	return (str);
}
