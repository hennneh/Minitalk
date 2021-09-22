/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:53:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/09/07 14:51:47 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char		arr[12];
	int			c;
	long int	nbim;

	c = 0;
	nbim = nb;
	if (nbim == 0)
		ft_putchar('0');
	if (nbim < 0)
	{
		ft_putchar('-');
		nbim *= (-1);
	}
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
	{
		ft_putchar(arr[c - 1]);
		c--;
	}
}
