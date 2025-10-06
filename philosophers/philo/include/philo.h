#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <time.h>

typedef struct s_philo_data
{
	int	number_of_philosophers;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	number_of_time_each_philo_eat;
}		t_philo_data;

#endif 