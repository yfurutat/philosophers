/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:54:09 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 21:39:06 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
	HEADERS
*/

// # include "philo_utils.h"
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <stdint.h>
# include <unistd.h> // write, usleep
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <sys/time.h> // gettimeofday
# include <pthread.h> 
// pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, 
// pthread_mutex_lock, pthread_mutex_unlock

/*
	MACROS
*/

# define POSITIVE (1)
# define NEGATIVE (-1)
# define ACT_FORK "has taken a fork"
# define ACT_EAT "is eating"
# define ACT_SLEEP "is sleeping"
# define ACT_THINK "is thinking"
# define ACT_DEAD "died"

/*
	TYPEDEF
*/

typedef uintmax_t t_time;

typedef struct s_param {
	long long		num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		min_times_to_eat;
	bool			the_end_status;
	pthread_mutex_t	coffin_lock;
	t_time 			start_time;
}	t_param;
	// time_t 		start_time;
	// size_t		last;

typedef struct s_philo {
	long long		id;
	long long		eat_times;
	t_time			last_eat_time;
	pthread_mutex_t	*dine;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	t_param			*pr;
}	t_ph;

typedef struct s_data {
	t_ph			*philos;
	t_param			pr;
	pthread_t		*threads;
	pthread_mutex_t	*dine;
	pthread_mutex_t	*forks;
}	t_data;

typedef enum e_error {
	OK = 0,
	E_EMPTY = -1,
	E_INVALID_ARGC = -2,
	E_NONDIGIT = -3,
	E_INVALID_LEN = -4,
	E_INVALID_VALUE = -5,
	E_ALLOC = -6,
	E_INITF = -7,
	E_DEAD = -8,
	FULL = -9,
}	t_err;

typedef enum e_atol {
	FLOW = 1,
}	t_atol;

/*
	FUNCTIONS
*/

int			prep_party(int argc, char **argv, t_data *data);
int			start_party(t_data *data);
int			monitor_party(t_data *data);
int			party_over(t_data *data);

int			parse_args(int argc, char **argv, t_param *pr);
int			init(t_data *data);
void		*act(void *param);

void		destroy_mutex_array(pthread_mutex_t *ptr, size_t num);
int			destroy_data(t_data *data);
int			print_msg(t_ph *philo, const char *action);
time_t		get_time(int *err_ptr);

int			ft_isspace(int chr);
int			ft_isdigit(int chr);
int			ft_aredigit_strs(char **strs);
long long	ft_atoll(const char *str);

// bool		ft_isdigit_str(char *str);
// size_t	ft_strlen(const char *str);

#endif