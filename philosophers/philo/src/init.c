#include "../include/philo.h"

/*
	assigns left fork as first one for philos with odd id
	and right one as second fork
	opposite for the philos with even id number
*/
int	init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(table->philos_nb * sizeof(t_philo));
	if (!table->philos)
		return (return_message("Error: malloc error when alocating philos", 1));
	i = 0;
	while (i < table->philos_nb)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meal_count = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].table = table;
		table->philos[i].first_fork =&table->forks[ (i + 1) % table->philos_nb].fork;
		table->philos[i].second_fork =  &table->forks[i].fork;
		if (table->philo[i].id % 2)
		{
			table->philos[i].first_fork = &table->forks[i].fork;
			table->philos[i].second_fork = &table->forks[ (i + 1) % table->philos_nb].fork;
		}
		i++;
	}
	return (0);
}

int	init_forks(t_table  *table)
{
	int	i;

	table->forks = malloc(sizeof(t_fork) * table->philos_nb);
	if (!table->forks)
		return (return_message("Error: malloc error when alocating forks", 1));
	i = 0;
	while (i < table->philos_nb)
	{
		if (safe_mutex_handle(&table->forks[i].fork, INIT) )
			return (1);
		table->forks[i].fork_id = i;
		i++;
	}
	table->correct_mutexes = i;
	return (0);
}

/*
	this function assigns input values to table variables
	and init whole simulation item: philos, forks etc
*/
int	init_table(t_table *table, int	argc, char **argv)
{
	int	i;

	table->dead_flag = false;
	table->threads_read = false;
	table->philos_nb = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat =  ft_atol(argv[3]) * 1e3;
	table->time_to_sleep =  ft_atol(argv[4]) * 1e3;
	table->must_eat_goal = -1;
	if (argc == 6)
		table->must_eat_goal =  ft_atol(argv[5]);
	if (init_forks(table))
		return (1);
	table->correct_mutexes = i;
	if (safe_mutex_handle(&table->dead_lock, INIT) != 0)
		return (1);
	if (safe_mutex_handle(&table->write_lock, INIT) != 0)
		return (1);
	if (safe_mutex_handle(&table->table_lock, INIT) != 0)
		return (1);
	if (init_philo(table))
		return (1);
	return (0);
}
