#include "../include/philo.h"

void	philo_thinking(t_philo *philo, bool pre_sym)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_sym)
		print_status(philo, THINKING);
	if (philo->table->philos_nb % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * (42 / 100), philo->table);
}

void	*alone_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_all_threads(philo->table);
	set_long(&philo->philo_lock, &philo->last_meal_time, get_time_in_ms());
	increase_long(&philo->table->table_lock, &philo->table->runned_threads_num);
	print_status(philo, TAKE_FIRST_FORK);
	while (!simulation_finished(philo->table))
		ft_usleep(200, philo->table);
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	print_status(philo, TAKE_FIRST_FORK);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	print_status(philo, TAKE_SECOND_FORK);
	set_long(&philo->philo_lock, &philo->last_meal_time, get_time_in_ms());
	safe_mutex_handle(&philo->philo_lock, LOCK);
	philo->meal_counter++;
	safe_mutex_handle(&philo->philo_lock, UNLOCK);
	print_status(philo, EATING);
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->must_eat_goal > 0
		&& philo->meal_counter == philo->table->must_eat_goal)
		set_bool(&philo->philo_lock, &philo->full, true);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_all_threads(philo->table);
	set_long(&philo->philo_lock, &philo->last_meal_time,
		get_time_in_ms());
	increase_long(&philo->table->table_lock,
		&philo->table->runned_threads_num);
	de_synchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_lock, &philo->full))
			break ;
		philo_eat(philo);
		print_status(philo, SLEEPING);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		philo_thinking(philo, false);
	}
	return (NULL);
}

void	start_dinner(t_table *table, int i)
{
	if (table->must_eat_goal == 0)
		return ;
	else if (table->philos_nb == 1)
		safe_thread_handle(&table->philos[0].thread_id, alone_philo,
			&table->philos[0], CREATE);
	else
	{
		while (++i < table->philos_nb)
		{
			if (safe_thread_handle(&table->philos[i].thread_id,
					dinner_simulation, &table->philos[i], CREATE))
				return ;
		}
	}
	if (safe_thread_handle(&table->monitor, dinner_monitoring, table, CREATE))
		return ;
	table->start_time = get_time_in_ms();
	set_bool(&table->table_lock, &table->threads_ready, true);
	i = -1;
	while (++i < table->philos_nb)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_lock, &table->dead_flag, true);
	safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
}
