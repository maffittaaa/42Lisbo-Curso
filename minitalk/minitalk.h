#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	deciding_sig(int sig);
int		send_message(int pid, char *str);


#endif