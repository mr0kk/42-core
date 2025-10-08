/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:20:38 by rmrok             #+#    #+#             */
/*   Updated: 2025/10/08 20:51:01 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void	*test_func(void *arg)
{
	pthread_t this_thread;

	this_thread = pthread_self();
	printf("Current thread ID: %lu\n",
		   (unsigned long)this_thread);
	while (1)
	{
		printf("thred is running\n");
		sleep(1);
	}	
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_philo_data data;
	pthread_t	thred_ptr;
	// if (!(argc == 5 || argc == 6))
	// if (!is_input_valid(argc, argv))
	// 	exit_with_error("Invalid input\n");
	// check params amount 
	// check if params are valid
	// start simulation
	// close simualtion -> exit	

	pthread_create(&thred_ptr, NULL, test_func, NULL);
	sleep(5);
	printf("in main\n");
	sleep(4);
	pthread_cancel(thred_ptr);
	
	pthread_join(thred_ptr, NULL);
	printf("Main thread finished.\n");
	return (0);
}