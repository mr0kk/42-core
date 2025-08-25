/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:39 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/25 23:33:19 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	sent_char(unsigned char c, int server_pid)
{
	unsigned char	bit;
	int				i;

	i = 8;
	bit = c;
	while (i > 0)
	{
		i--;
		bit = (c >> i) & 1;
		if (bit % 2 == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	int			server_pid;
	const char	*message;

	if (argc != 3)
	{
		ft_printf("usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	if (server_pid <= 0)
	{
		ft_printf("Error: invalid PID\n");
		exit(1);
	}
	i = 0;
	while (message[i])
	{
		sent_char(message[i], server_pid);
		i++;
	}
	sent_char('\0', server_pid);
	exit(0);
}
