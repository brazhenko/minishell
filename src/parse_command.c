//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include "minishell.h"

static void			print_commandvv(char ***commandvv)
{
	while (*commandvv)
	{
		ft_putendl("command:");
		while (**commandvv)
		{
			ft_putendl(**commandvv);
			(*commandvv)++;
		}
		commandvv++;
	}
}

static int 			command_count(char **commandv)
{
	int		c;

	c = 0;
	while (*commandv)
	{
		commandv++;
		c++;
	}
	return (c);
}

char				***parse_command(char *command)
{
	char		**commandv;
	char		***commandvv;
	int			commandc;

	commandv = ft_strsplit(command, ';');
	commandc = command_count(commandv);
	commandvv = (char ***)malloc(sizeof(char **) * (commandc + 1));
	commandvv[commandc] = NULL;
	while (commandc--)
	{
		commandvv[commandc] = ft_strsplit(commandv[commandc], ' ');
	}
	return (commandvv);
}