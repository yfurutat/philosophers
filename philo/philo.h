/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:03:50 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/27 10:03:23 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> // write, usleep
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <sys/time.h> // gettimeofday
# include <pthread.h> 
// pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, 
// pthread_mutex_lock, pthread_mutex_unlock

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat
// philo_id

typedef struct s_philo {
	ssize_t		id;
	pthread_t	think;
	pthread_t	eat;
	pthread_t	sleep;
}	t_ph;

// [timestamp_in_ms] X has taken a fork
// [timestamp_in_ms] X is eating
// [timestamp_in_ms] X is sleeping
// [timestamp_in_ms] X is thinking
// [timestamp_in_ms] X died



#endif