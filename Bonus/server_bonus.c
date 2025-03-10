/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:39:21 by claghrab          #+#    #+#             */
/*   Updated: 2025/03/10 20:15:58 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static char	character = 0;
	static int	bit_count;

	(void)context;
	if (signum == SIGUSR2)
		character |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8 && character == '\0')
		kill(info->si_pid, SIGUSR1);
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("My PID is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
