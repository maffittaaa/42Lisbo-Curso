
#include "minitalk.h"

char	g_counter = 0;

void    deciding_sig(int sig)
{
	if (sig == SIGUSR1)
		g_counter++;
	else if (sig == SIGUSR2)
	{
		write(1, &g_counter, 1);
		g_counter = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	printf("PID from Server is: %d\n", pid);
	signal(SIGUSR1, deciding_sig);
	signal(SIGUSR2, deciding_sig);
	while (1)
		pause();
	return (0);
}