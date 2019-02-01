#include "minishell.h"


//int	 execve(const char * __file, char * const * __argv, char * const * __envp) __WATCHOS_PROHIBITED __TVOS_PROHIBITED;
int                 main(void)
{
    pid_t pid;
    char *const parmList[] = {"/bin/ls", "-l", NULL};
    char *const envParms[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};

    if ((pid = fork()) ==-1)
        perror("fork error");
    else if (pid == 0) {
        execve("/bin/ls", parmList, envParms);
        printf("Return not expected. Must be an execve error.n");
    }
}