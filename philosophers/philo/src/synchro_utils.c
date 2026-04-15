#include "../include/philo.h"

/*
	waits for variable threads_ready to be true (spinlock)
*/
void	wait_for_all_threads(t_table *table)
{
	while (!get_bool(&table->table_lock, &table->threads_ready))
		;
}
