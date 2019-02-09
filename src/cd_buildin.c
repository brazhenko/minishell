//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include "minishell.h"

int     ft_change_dir(char *path)
{
    char *pwd;
    char buff[PATH_MAX + 1];

    pwd = getcwd(buff, 4096);
    if (!chdir(path))
    {
//        setenv("PWDOLD", pwd);
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

int     cd_builtin(char **argv, char **envp)
{
    char *home;

    home = get_env("HOME", envp);
    if (!argv[1])
    {
        ft_change_dir(home);
    }
    else
    {
        if (ft_strequ(argv[1], "--"))
        {
            ft_change_dir(home);
            return (1);
        }

//        else if (argv[0][0] == '-' && !argv[0][1])
//        {
//            ft_change_dir(get_env("PWDOLD"));
//            return (1);
//        }
        else
        {
            ft_change_dir(argv[1]);
            return (1);
        }
    }
    return (0);
}
