//
// Created by Andrew Brazhenko on 2019-02-10.
//

#include "minishell.h"

/*
 * 		Parses system char** envp copy and returns a
 * 		new char* if an env var is found
 * 		or the old param instead.
 */

char	 			*try_get_env(char *str, char **envp)
{
	char	*env_var;

	env_var = get_env(str + 1, envp);
	if (str && *str == '$')
		return (env_var ? env_var : str);
	return (str);
}