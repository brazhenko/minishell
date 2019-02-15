
#ifndef MINISHELL_H
# define MINISHELL_H
# define HISTORY .shell_history

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <signal.h>

void 				execute_process(char *path, char *name, char **params, char **envs);
char 				*get_env(char *name, char **envp);
char				*parse_path(char *name, char **envs);
int 				ft_strbsn_len(char *str);
char 				*str_till_bsn(char *str);
int 			    cd_builtin(char **argv, char **envp);
void				env_builtin(char **envp);
char	 			*try_get_env(char *str, char **envp);
char				***parse_command(char *command, char **envp);
void 				echo_builtin(char **argv, char **envp);
void				ctrl_c(int sig);
char	 			***prompt(char **v, char **envp);
int 				delete_commandvv(char ***commandvv);


#endif