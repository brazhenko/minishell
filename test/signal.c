#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>

void     INThandler(int);

int  main(void)
{
	    signal(SIGINT, INThandler);
		      while (1);
		return 0;
}

void  INThandler(int sig)
{
      signal(sig, SIG_IGN);
      exit(0);
}
