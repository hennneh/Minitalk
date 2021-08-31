#include "minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	ft;

	if (argc != 3)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (!strlen(agrv[2]));
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	return (0);
}
