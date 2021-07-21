#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	return(0);
}
