#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	bin(int i)
{
	int j;
	int	val;

	val = 0;
	j = 0;
	if (i == 0 && j < 9)
		val = val * 10 + i;
	else if (i == 1 && j < 9)
		val = val * 10 + i;
	else
		return (-1);
	
}

void	one()
{
	bin(1);
}

void	zero()
{
	bin(0);
}

void	sighandler()
{
	printf("signal received, will terminate now...\n");
	exit(1);
}

void	ft_putnbr(pid_t nbr)
{
	char	c;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, sighandler);
		printf("sleeping for a sec... ZzZzZ...\n");
		sleep(1);
	}
	return (0);
}
