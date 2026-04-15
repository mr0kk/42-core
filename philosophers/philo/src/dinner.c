#include "../include/philo.h"

static void	philo_thinking(t_philo *philo)
{
	print_status(philo, THINKING);
}

static void	philo_eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	print_status(philo, TAKE_FIRST_FORK);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	print_status(philo, TAKE_SECOND_FORK);

	set_long(&philo->philo_lock, &philo->last_meal_time, get_time_in_ms());
	philo->meal_counter++;
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

	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ; // to do: is thread safe?


		philo_eat(philo);

		print_status(philo, SLEEPING);
		ft_usleep(philo->table->time_to_sleep, philo->table);


		philo_thinking(philo);
	}	

	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	if (table->must_eat_goal == 0)
		return ;
	else if (table->philos_nb == 1)
		; // to do, one philo hamndling
	else
	{
		while (i < table->philos_nb)
		{
			if (safe_thread_handle(&table->philos[i].thread_id, 
				dinner_simulation, &table->philos[i], CREATE))
				return ;
			table->runned_threads = i;
			i++;
		}
 	}
	printf("here\n");
	table->start_time = get_time_in_ms();


	set_bool(&table->table_lock, &table->threads_ready, true);
	
	printf("here2\n");

	i = -1;
	while (++i < table->philos_nb)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	printf("here3\n");
}
