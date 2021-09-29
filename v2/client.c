#include "minitalk.h"

t_ack	g_ack;

void	send_bit_by_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift <= 7)
		{
			g_ack.acked = 0;
			if ((msg[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			while (g_ack.acked == 0)
				pause();
		}
		i++;
	}
}

void	get_ack(int sigbit, siginfo_t *siginfo, void *context)
{
	(void) sigbit;
	(void) siginfo;
	(void) context;
	g_ack.acked = 1;
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	g_ack.acked = 1;
	sig.sa_sigaction = &get_ack;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bit_by_bit(pid, av[2], ft_strlen(av[2]));
	}
	else
		ft_putstr("wrong parameters try again\n");
	return (0);
}
