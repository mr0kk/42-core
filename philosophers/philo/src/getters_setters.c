#include "../include/philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	res;

	safe_mutex_handle(mutex, LOCK);
	res = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (res);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	res;

	safe_mutex_handle(mutex, LOCK);
	res = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (res);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_lock, &table->dead_flag));
}
