//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include <dirent.h>
#include "minishell.h"

char 			*str_till_bsn(char *str)
{
	int		len;
	char 	*raw_str;

	len = ft_strbsn_len(str);
	raw_str = (char *)malloc(sizeof(char) * len);
	raw_str[--len] = '\0';
	while (len--)
		raw_str[len] = str[len];
	return (raw_str);
}

char			*parse_path(char *name, char **envs)
{
	DIR					*dir;
	char				**path;
	struct dirent		*file;

	path = ft_strsplit(get_env("PATH", envs), ':');
	while (*path)
	{
		dir = opendir(*path);
		if (dir)
		{
			while ((file = readdir(dir)))
			{
				if (ft_strcmp(file->d_name, name) == 0)
					return (*path);
			}
			closedir(dir);
		}
		path++;
	}
	return (NULL);
}

void 				exe_process(char *path, char *name, char **params, char **envs)
{
	pid_t pid;

	if (path && name && params && *params)
	{
		if ((pid = fork()) == -1)
			ft_putstr("fork error");
		else if (pid == 0)
		{
			execve(ft_strjoin(ft_strjoin(path, "/"), name), params, envs);
		}
		wait(NULL);
	}
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(name);
	}
}