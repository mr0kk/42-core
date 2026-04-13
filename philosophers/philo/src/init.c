#include "../include/philo.h"

int	init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(table->philos_nb * sizeof(t_philo));
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->philos_nb)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meal_count = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[ (i + 1) % table->philos_nb];
		i++;
	}
	return (0);
}

int	init_forks(t_table  *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos_nb);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->philos_nb)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	table->correct_mutexes = i;
	
	return (0);
}

int	init_table(t_table *table, int	argc, char **argv)
{
	int	i;

	table->philos_nb = ft_atoi(argv[1]);
	table->time_to_die = ft_atosize(argv[2]);
	table->time_to_eat =  ft_atosize(argv[3]);
	table->time_to_sleep =  ft_atosize(argv[4]);
	table->must_eat_goal = -1;
	if (argc == 6)
		table->must_eat_goal =  ft_atoi(argv[5]);
	if (init_forks(table))
		return (1);
	table->correct_mutexes = i;
	if (pthread_mutex_init(&table->dead_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
		return (1);
	if (init_philo(table))
		return (1);

	i = 0;
	while (i < table->philos_nb)
	{
		printf("philo number: %d\tid: %d\tleft fork: %p\tright fork: %p\n",
		i, table->philos[i].id, table->philos[i].left_fork, table->philos[i].right_fork);
			i++;
	}
	return (0);
}
