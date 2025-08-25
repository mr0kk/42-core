/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:29 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/25 23:36:14 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	recive_message(int sig_num)
{
	static int	i = 0;
	static char	res = 0;

	res |= (sig_num == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (res == '\0')
			write(1, "\n", 1);
		else
			write(1, &res, 1);
		i = 0;
		res = 0;
	}
	else
		res <<= 1;
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("%d\n", getpid());
	s_action.sa_handler = recive_message;
	sigemptyset(&s_action.sa_mask);
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();	
	return (0);
}
