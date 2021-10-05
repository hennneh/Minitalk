#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

typedef struct	s_msg
{
	char	c;
	int		size;
}			t_msg;

typedef struct s_ack
{
	int	acked;
}			t_ack

#endif
