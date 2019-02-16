/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 07:46:52 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/16 07:46:55 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include ".shell_config.h"

char					***prompt(char **v, char **envp)
{
	char *command;
	char ***commandvv;
	char *path;

	command = ft_strnew(2048);
	ft_putstr(PROMPT_COLOR);
	ft_putstr("➜ ");
	path = getcwd(NULL, 1);
	ft_putstr(PWD_COLOR);
	ft_putstr(path);
	free(path);
	ft_putstr(CROSS_COLOR);
	ft_putstr(" ✗ ");
	ft_putstr(COMMAND_COLOR);
	read(STDIN_FILENO, command, 2048);
	ft_putstr(DEFAULT_COLOR);
	commandvv = parse_command(str_till_bsn(command), envp);
	free(command);
	return (commandvv);
}
