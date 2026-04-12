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

int	free_everything(t_table *table, int return_val)
{
	int	i;

	if (!table)
		return (return_val);
	if (table->forks)
	{
		i = 0;
		while (i < table->correct_mutexes)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->dead_lock);
    pthread_mutex_destroy(&table->write_lock);
	if (table->philos)
		free(table->philos);
	return (return_val);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
		{
			printf("Error: Argument %d is not a valid positive number.\n", i);
			return (1);
		}
		i++;
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		printf("Error: Need at least 1 philosopher.\n");
		return (1);
	}
    return (0);
}

int main(int argc, char *argv[])
{
	t_table table;

	if (check_args(argc, argv))
		return (1);
	if (init_table(&table, argc, argv));
		return (free_everything(&table, 1));

	
	free_everything(&table, 0);
	return (0);
}
