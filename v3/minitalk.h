#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

typedef struct	s_message
{
	char	c;
	int		size;
}			t_message;

typedef struct s_acknowledge
{
	int	acknowledged;
}			t_acknowledge;

#endif
