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
#include <time.h>

typedef struct	s_table t_table;
typedef struct	s_philo t_philo;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				meal_count;
	size_t			last_meal_time;
	pthread_mutex_t *left_fork;
	pthread_mutex_t	*right_fork;
	t_table 		*table;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				philos_nb;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat_goal;
	size_t			start_time;
	int				dead_flag;
	int				correct_mutexes;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
}	t_table;

/*
	init.c
*/
int	init_table(t_table *table, int	argc, char **argv);

/*
	time_management.c
*/

/*
	utils.c
*/
int		ft_isdigit(int c);
int		is_digit_str(char *str);
int		ft_atoi(const char *nptr);
size_t	ft_atosize(const char *nptr);

#endif 