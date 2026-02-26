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
	int *id_ptr = (int *)arg;

	int id = *id_ptr;
	printf("zaczynam prace w watku %d\n", id);
	sleep(2);
	printf("koniec pracy watku: %d\n", id);
	return (NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1;
	pthread_t thread2;

	int id1 = 1;
	int	id2 = 2;

	printf("main: tworzymy watek\n");


	pthread_create(&thread1, NULL, &test_func, &id1);
	pthread_create(&thread1, NULL, &test_func, &id2);
	
	printf("main: czekam az watki sie skoncza..\n");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("main: koniec watkow zamykamy\n");
	return (0);
}