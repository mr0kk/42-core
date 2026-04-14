/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:20:30 by rmrok             #+#    #+#             */
/*   Updated: 2025/10/08 20:44:20 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

typedef struct	s_table t_table;
typedef struct	s_philo t_philo;


typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				meal_count;
	int				full;
	size_t			last_meal_time;
	pthread_mutex_t *first_fork;
	pthread_mutex_t	*second_fork;
	t_table 		*table;
}	t_philo;

typedef struct s_table
{
	long			philos_nb;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_goal;
	long			start_time;
	bool			dead_flag;
	int				correct_mutexes;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
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

/*
	init.c
*/
int	init_table(t_table *table, int	argc, char **argv);

/*
	time_management.c
*/
long long	get_time_in_ms(void);
void		ft_usleep(long long time_in_ms);

/*
	safe_handling.c
*/
int	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode op_code);
int			safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
					 void *data,  t_opcode op_code);
/*
	utils.c
*/
int		ft_isdigit(int c);
int		is_digit_str(const char *str);
long	ft_atol(const char *str);
int	return_message(char *message, int value);

#endif 