/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:45:48 by gizawahr          #+#    #+#             */
/*   Updated: 2021/09/07 15:55:57 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_msg
{
	char		c;
	size_t		size;
}				t_msg;

typedef struct s_ack
{
	int			acked;
}				t_ack;

#endif
