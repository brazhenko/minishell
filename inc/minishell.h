
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

void 				exe_process(char *path, char *name, char **params, char **envs);
char 				*get_env(char *name, char **envp);
char				***parse_command(char *command);
char				*parse_path(char *name, char **envs);
int 				ft_strbsn_len(char *str);
char 				*str_till_bsn(char *str);
int 			    cd_builtin(char **argv, char **envp);