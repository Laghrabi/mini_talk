/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:39:56 by claghrab          #+#    #+#             */
/*   Updated: 2025/03/13 13:53:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(800);
}

void	send_string(int pid, const char *str)
{
	int	i;
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
}

int	main(int ac, char **av)
{
	int			server_pid;
	const char	*message;

	if (ac != 3)
		return (0);
	server_pid = atoi(av[1]);
	message = av[2];
	send_string(server_pid, message);
	return (0);
}
