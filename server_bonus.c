#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void    handle_signal(int signum, siginfo_t *info, void *context)
{
    static char character = 0;
    static int bit_count;

    (void)context;
    if (signum == SIGUSR2)
        character |= (1 << (7 - bit_count));
    bit_count++;
	if ( bit_count == 8 && character == '\0')
			kill(info->si_pid, SIGUSR1);
    if (bit_count == 8)
    {
        //printf("%c", character);
        write(1, &character, 1);
		
        bit_count = 0;
        character = 0;
        // kill(info->si_pid, SIGUSR1);
    }
}

int main()
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("My PID is: %d\n", getpid());
    while (1)
        pause();
    return 0;
}
