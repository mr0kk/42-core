/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:20:30 by rmrok             #+#    #+#             */
/*   Updated: 2026/04/18 18:24:59 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	long			meal_counter;
	bool			full;
	long			last_meal_time;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_mutex_t	philo_lock; // for races with monitor
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	pthread_t		monitor;
	long			philos_nb;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_goal;
	long			start_time;
	bool			dead_flag; //ens_simulation
	bool			threads_ready;
	int				correct_mutexes;
	long			runned_threads_num;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	table_lock;
	t_philo			*philos;
	t_fork			*forks;
}	t_table;

/*
	codes for mutexes and threads
*/
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

/*
	init.c
*/
int		init_table(t_table *table, int argc, char **argv);
/*
	dinner.c
*/
void	start_dinner(t_table *table, int i);
void	philo_thinking(t_philo *philo, bool pre_sym);
/*
	monitoring.c
*/
void	*dinner_monitoring(void *data);

/*
	getters_setters.c
*/
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
long	get_long(pthread_mutex_t *mutex, long *value);
bool	simulation_finished(t_table *table);

/*
	synchro_utils.c
*/
void	wait_for_all_threads(t_table *table);
bool	all_threads_running(pthread_mutex_t *mutex, long *threads, long philo);
void	increase_long(pthread_mutex_t *mutex, long *value);
void	de_synchronize_philos(t_philo *philo);
/*
	time_management.c
*/
long	get_time_in_ms(void);
void	ft_usleep(long time_in_ms, t_table *table);

/*
	print_status.c
*/
void	print_status(t_philo *philo, t_philo_status status);

/*
	safe_handling.c
*/
int		safe_mutex_handle(pthread_mutex_t *mutex, t_opcode op_code);
int		safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode op_code);
/*
	utils.c
*/
int		ft_isdigit(int c);
int		is_digit_str(const char *str);
long	ft_atol(const char *str);
int		return_message(char *message, int value);

#endif