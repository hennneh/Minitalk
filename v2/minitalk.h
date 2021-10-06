#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

typedef struct	s_msg
{
	char	c;
	int		size;
}			t_msg;

typedef struct s_ack
{
	int	acked;
}			t_ack;

size_t	ft_strlen(const char *str);
int ft_atoi(const char *nptr);
void    ft_putchar(char c);
void    ft_putnbr(int n);
void    ft_putstr(char *s);

#endif
