//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include "minishell.h"

char 					*get_env(char *name, char **envp)
{
	while (*envp)
	{
		if (ft_strstr(*envp, name))
		{
			return (ft_strsplit(*envp, '=')[1]);
		}
		envp++;
	}
	return (NULL);
}