/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:28:35 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:28:36 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**static void			print_commandvv(char ***commandvv)
**{
**	while (*commandvv)
**	{
**		ft_putendl("command:");
**		while (**commandvv)
**		{
**			ft_putendl(**commandvv);
**			(*commandvv)++;
**		}
**		commandvv++;
**	}
**}
*/

static int			command_count(char **commandv)
{
	int		c;

	c = 0;
	while (commandv[c])
	{
		c++;
	}
	return (c);
}

char				**parse_for_envs(char **commandv, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (commandv && commandv[i])
	{
		tmp = commandv[i];
		commandv[i] = try_get_env(commandv[i], envp);
		if (commandv[i] != tmp)
			free(tmp);
		i++;
	}
	return (commandv);
}

static void			del_commandv(char **commandv)
{
	int		i;

	i = 0;
	while (commandv[i])
	{
		free(commandv[i]);
		i++;
	}
	free(commandv);
}

char				***parse_command(char *command, char **envp)
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
		commandvv[commandc] = parse_for_envs(ft_strsplit(commandv[commandc],
				' '), envp);
	}
	del_commandv(commandv);
	free(command);
	return (commandvv);
}
