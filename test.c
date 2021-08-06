#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	sighandler(int signum)
{
	printf("caught signal %d...\n", signum);
	exit (1);
}

int	main(void)
{
	printf("beginning");
	signal(SIGINT, sighandler);

	while(1)
	{
		printf("waiting for 1 second...\n");
		sleep(1);
	}
	return (0);
}
