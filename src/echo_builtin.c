//
// Created by Andrew Brazhenko on 2019-02-10.
//

#include "minishell.h"

void 			echo_builtin(char **argv, char **envp)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}