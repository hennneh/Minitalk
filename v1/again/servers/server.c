#include "../includes/minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0;
	static int				counter = 0;
	static pid_t			pid = 0;

	(void)unused;
	if (!pid)
		pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++counter == 8)
	{
		counter = 0;
		if (c == 0)
		{
			pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	ft;

	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	ft.sa_flags = SA_SIGINFO;
	ft.sa_sigaction = handler;
	sigaction(SIGUSR1, &ft, 0);
	sigaction(SIGUSR2, &ft, 0);
	while (1)
		pause();
	return (0);
}
