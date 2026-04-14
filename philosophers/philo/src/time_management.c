#include "../include/philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < time_in_ms)
		usleep(200);
}

