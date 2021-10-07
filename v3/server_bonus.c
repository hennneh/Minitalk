/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:54:48 by hlehmann          #+#    #+#             */
/*   Updated: 2021/02/13 16:57:26 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int bit, siginfo_t *siginfo, void *context)
{
	static t_msg	msg;

	if (bit == SIGUSR1)
		msg.c += (0 << msg.size);
	if (bit == SIGUSR2)
		msg.c += (1 << msg.size);
	msg.size++;
	if (msg.size == 8)
	{
		ft_putchar(msg.c);
		msg.c = 0;
		msg.size = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
	(void) context;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &receive;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
}
