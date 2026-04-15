#include "../include/philo.h"

void	print_status(t_philo *philo, t_philo_status status)
{
	long	time_now;

	if (get_bool(&philo->philo_lock, &philo->full))
		return ;
	time_now = get_time_in_ms() - philo->table->start_time;
	safe_mutex_handle(&philo->table->write_lock, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", time_now, philo->id);
	else if (status == EATING && !simulation_finished(philo->table))
		printf("%-6ld %d is eating\n", time_now, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", time_now, philo->id);
	else if (status == THINKING && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", time_now, philo->id);
	else if (status == DIED)
		printf("%-6ld %d died\n", time_now, philo->id);
	safe_mutex_handle(&philo->table->write_lock, UNLOCK);
}
