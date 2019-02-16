/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:23:02 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:23:05 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_is_child = 0;
pid_t					g_pid = -1;

void			ctrl_c(int sig)
{
	signal(sig, SIG_IGN);
	if (g_pid > 0)
	{
		kill(g_pid, SIGINT);
	}
	write(1, "\n", 1);
}

char			*str_till_bsn(char *str)
{
	int		len;
	char	*raw_str;

	len = ft_strbsn_len(str);
	raw_str = (char *)malloc(sizeof(char) * len);
	raw_str[--len] = '\0';
	while (len--)
		raw_str[len] = str[len];
	return (raw_str);
}

static void 	del_pathv(char **path, char *pathvalue)
{
	int 			i;

	i = 0;
	while (path[i])
	{
		if (!ft_strequ(path[i], pathvalue))
		{
			free(path[i]);
		}
		i++;
	}
	free(path);
}

char			*parse_path(char *name, char **envs)
{
	DIR					*dir;
	char				**path;
	struct dirent		*file;
	int 				i;
	char 				*pathvalue;
	char 				*env;

	i = 0;
	pathvalue = NULL;
	env = get_env("PATH", envs);
	path = ft_strsplit(env, ':');
	free(env);
	while (path[i])
	{
		dir = opendir(path[i]);
		if (dir)
		{
			while ((file = readdir(dir)))
			{
				if (ft_strequ(file->d_name, name))
				{
					closedir(dir);
					pathvalue = path[i];
					del_pathv(path, pathvalue);
					return (pathvalue);
				}
			}
			closedir(dir);
		}
		i++;
	}
	return (pathvalue);
}

void			execute_process(char *path, char *name, char **params, char **envs)
{
	signal(SIGINT, ctrl_c);
	if (path && name && params && *params)
	{
		if ((g_pid = fork()) == -1)
			ft_putstr("fork error");
		else if (g_pid == 0)
		{
			g_is_child = 1;
			execve(ft_strjoin(ft_strjoin(path, "/"), name), params, envs);
		}
		else if (g_pid > 0)
			wait(&g_pid);
	}
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(name);
	}
	free(path);
}
