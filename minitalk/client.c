#include "minitalk.h"

void    send_msg(int server_pid, char msg)
{
    int bits;

    bits = 7;
    while (bits >= 0)
    {
        if (msg > bits)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        sleep(50000);
        bit--;
    }
}

int check_input(int argc, char **argv)
{
    
}

int main(int argc, char **argv)
{

}