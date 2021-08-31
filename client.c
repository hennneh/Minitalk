#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (argc > 1)
		pid = ft_atoi(argv[1]);
	if (argc > 2)
		msg = argv[2];
	printf("%d\n", pid);
	printf("%s\n", msg);
	kill(pid, SIGUSR1);
	return (0);
}
