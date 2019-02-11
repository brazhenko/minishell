/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:21:12 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:21:14 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_change_dir(char *path)
{
	char *pwd;
	char buff[PATH_MAX + 1];

	pwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
//		setenv("PWDOLD", pwd);
		return (1);
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
		return (0);
	}
}

int			cd_builtin(char **argv, char **envp)
{
	if (!argv[1] || ft_strequ(argv[1], "--"))
	{
		ft_change_dir(try_get_env("$HOME", envp));
	}
	else if (ft_strequ(argv[1], "-"))
	{
		ft_change_dir(try_get_env("$OLDPWD", envp));
	}
	else
	{
		ft_change_dir(try_get_env(argv[1], envp));
	}
	return (0);
}
