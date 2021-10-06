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
