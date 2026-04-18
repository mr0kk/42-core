#include "../include/philo.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (return_message("Error: gettimeofday failed", 0));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long time_in_ms, t_table *table)
{
	long	start_time;
	long	elapsed;
	long	rem;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < time_in_ms)
	{
		if (simulation_finished(table))
			break ;
		elapsed = get_time_in_ms() - start_time;
		rem = time_in_ms - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
			while (get_time_in_ms() - start_time < time_in_ms)
				usleep(100);
	}
}
