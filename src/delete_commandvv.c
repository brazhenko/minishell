#include "minishell.h"

int 			delete_commandvv(char ***commandvv)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (commandvv[i])
	{
		while (commandvv[i][j])
		{
			free(commandvv[i][j]);
			j++;
		}
		free(commandvv[i]);
		j = 0;
		i++;
	}
	free(commandvv);
}