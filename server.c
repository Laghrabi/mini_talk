#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void    handle_signal(int signum)
{
    static char character = 0;
    static int bit_count;

    if (signum == SIGUSR2)
        character |= (1 << (7 - bit_count));
    bit_count++;
    if (bit_count == 8)
    {
        //printf("%c", character);
        write(1, &character, 1);
        bit_count = 0;
        character = 0;
    }
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("My PID is: %d\n", getpid());
    while (1)
        pause();
    return 0;
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//         return 0;
//     char c = av[1][0];
//     int i = 0;
//     int mask = 0;
//     int bit = 0;
//     while (i < 8)
//     {
//         mask = 1 << (7 - i);
//         bit = (c & mask) >> (7 - i);
//         printf("bit = %d\n", bit);
//         i++;
//     }
//     return 0;
// }