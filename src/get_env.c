//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include "minishell.h"

char 					*get_env(char *name, char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], name))
		{
			return (ft_strsplit(envp[i], '=')[1]);
		}
		i++;
	}
	return (NULL);
}