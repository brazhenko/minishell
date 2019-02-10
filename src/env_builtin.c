//
// Created by Andrew Brazhenko on 2019-02-10.
//

#include "minishell.h"

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