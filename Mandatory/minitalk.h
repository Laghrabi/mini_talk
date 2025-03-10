/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:26 by claghrab          #+#    #+#             */
/*   Updated: 2025/03/10 19:41:34 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "../printf/ft_printf.h"

/* FUNCTIONS */
void	send_string(int pid, const char *str);
void	send_bit(int pid, int bit);
void	handle_signal(int signum);

#endif