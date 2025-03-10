#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void    handle_ack(int signum)
{
    (void)signum;
    write(1, "done\n", 5);
}

void send_bit(int pid, int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(100);
}

void	send_string(int pid, const char *str)
{
	int i;
	int	bit;

	if (str == NULL)
		return ;
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			bit = 1 & (*str >> i);
			send_bit(pid, bit);
			i--;
		}
		str++;
	}
    i = 7;
    while (i >= 0)
    {
        send_bit(pid, 0);
        i--;
    }
}

int	main(int ac, char** av)
{
    int			server_pid;
	const char	*message;

    if (ac != 3)
        return (0);
    signal(SIGUSR1, handle_ack);
    server_pid = atoi(av[1]);
	message = av[2];
	send_string(server_pid, message);
}
