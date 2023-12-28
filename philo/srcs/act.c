/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:47:24 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 18:16:39 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_philo_pick_up_fork(t_ph *philo);
static int	_philo_eat(t_ph *philo);
static int	_philo_sleep(t_ph *philo);
static int	_philo_think(t_ph *philo);

// 13L
void *act(void *param)
{
	t_ph *philo;

	philo = (t_ph *)param;
	while (1)
	{
		if (_philo_eat(philo))
			break ;
		if (_philo_sleep(philo))
			break ;
		if (_philo_think(philo))
			break ;
    }
	return (NULL);
}
	// long tid;
	// tid = (long)threadid;
	// philo->id = ;
    	// pthread_exit(NULL);
	// usleep(time_to_sleep);
	// printf("is thinking\n");
	// printf("has taken a fork\n");

// 14L
static int	_philo_pick_up_fork(t_ph *philo)
{
	pthread_mutex_lock(philo->fork_r);
	if (print_msg(philo, ACT_FORK) == E_DEAD)
	{
		pthread_mutex_unlock(philo->fork_r);
		return (E_DEAD);
	}
	pthread_mutex_lock(philo->fork_l);
	if (print_msg(philo, ACT_FORK) == E_DEAD)
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return (E_DEAD);
	}	
	return (OK);
}

// 18L
static int	_philo_eat(t_ph *philo)
{
	if (_philo_pick_up_fork(philo) != OK)
		return (E_DEAD);
	if (print_msg(philo, ACT_EAT) == E_DEAD)
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return (E_DEAD);
	}
	pthread_mutex_lock(philo->dine);
	philo->last_eat_time = get_time(NULL);
	usleep(philo->pr->time_to_eat * 1000);
	philo->eat_times++;
	pthread_mutex_unlock(philo->dine);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	if (philo->eat_times == philo->pr->min_times_to_eat)
		return (FULL);
	return (OK);
}

// 4L
static int	_philo_sleep(t_ph *philo)
{
	if (print_msg(philo, ACT_SLEEP) == E_DEAD)
		return (E_DEAD);
	usleep(philo->pr->time_to_sleep * 1000);
	return (OK);
}

// 3L
static int	_philo_think(t_ph *philo)
{
	if (print_msg(philo, ACT_THINK) == E_DEAD)
		return (E_DEAD);
	return (OK);
}
