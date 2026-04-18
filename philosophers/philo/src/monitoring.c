#include "../include/philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapse;
	long	t_to_die;

	if (get_bool(&philo->philo_lock, &philo->full))
		return (false);
	elapse = get_time_in_ms() - get_long(
			&philo->philo_lock, &philo->last_meal_time);
	t_to_die = philo->table->time_to_die;
	if (elapse > t_to_die)
		return (true);
	return (false);
}

void	*dinner_monitoring(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_lock, &table->runned_threads_num,
			table->philos_nb))
		;
	// wait_for_all_threads(table);
	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->philos_nb)
		{
			if (philo_died(table->philos + i) && !simulation_finished(table))
			{
				set_bool(&table->table_lock, &table->dead_flag, true);
				print_status(table->philos + i, DIED);
			}
			i++;
		}
	}
	return (NULL);
}
