/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:26:19 by gizawahr          #+#    #+#             */
/*   Updated: 2021/09/07 19:23:43 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit_by_bit(int bit, siginfo_t *siginfo, void *context)
{	
	static t_msg	msg;

	(void) context;
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
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &get_bit_by_bit;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr("Server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
