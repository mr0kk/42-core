/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#su r+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:20:38 by rmrok             #+#    #+#             */
/*   Updated: 2025/10/08 20:51:01 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *test_func(void *arg)
{
	printf("in thread\n");
	return (NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1;

	pthread_create(&thread1, NULL, test_func, NULL);
	
	pthread_join(thread1, NULL);
	return (0);
}