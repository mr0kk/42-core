#include "../include/philo.h"

/*
	waits for variable threads_ready to be true (spinlock)
*/
void	wait_for_all_threads(t_table *table)
{
	while (!get_bool(&table->table_lock, &table->threads_ready))
		;
}

bool	all_threads_running(
		pthread_mutex_t *mutex, long *threads, long philo_num)
{
	bool	res;

	res = false;
	safe_mutex_handle(mutex, LOCK);
	if (*threads == philo_num)
		res = true;
	safe_mutex_handle(mutex, UNLOCK);
	return (res);
}

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex_handle(mutex, LOCK);
	(*value)++;
	safe_mutex_handle(mutex, UNLOCK);
}

void	de_synchronize_philos(t_philo *philo)
{
	if (philo->table->philos_nb % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(30, philo->table);
	}
	else
	{
		if (philo->id % 2)
			philo_thinking(philo, true);
	}
}
