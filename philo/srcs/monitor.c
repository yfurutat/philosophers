/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:49:01 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 17:49:04 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	// while (1)
// 24L
int	monitor(t_data *data)
{
	size_t		i;
	long long	full_bellies;

	i = 0;
	full_bellies = 0;
	while (i < (size_t)data->pr.num_philos)
	{
		pthread_mutex_lock(data->philos[i].dine);
		if (get_time(NULL) - data->philos[i].last_eat_time > (t_time)data->pr.time_to_die)
		{
			print_msg(&data->philos[i], ACT_DEAD);
			data->pr.the_end_status = true;
			pthread_mutex_unlock(&data->pr.coffin_lock);
			pthread_mutex_unlock(data->philos[i].dine);
			return (E_DEAD);
		}
		if (data->philos[i].eat_times == data->pr.min_times_to_eat)
			full_bellies++;
		pthread_mutex_unlock(data->philos[i].dine);
		i++;
	}
	if (full_bellies == data->pr.num_philos)
		return (FULL);
	return (OK);
}
