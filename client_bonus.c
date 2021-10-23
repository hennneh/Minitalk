/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_ack	g_ack;

void	send(int pid, char *msg, size_t len)
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

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;

	g_ack.acked = 1;
	sig.sa_sigaction = &get_ack;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr("Wrong input!\n");
	return (0);
}
