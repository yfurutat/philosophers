/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:18:37 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 21:31:10 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 11L
int	prep_party(int argc, char **argv, t_data *data)
{
	int	err_id;

    memset(data, '\0', sizeof(t_data));
    err_id = parse_args(argc, argv, &(data->pr));
	if (err_id != OK)
		return (err_id);
    err_id = init(data);
	if (err_id != OK)
		return (err_id);
    data->pr.start_time = get_time(NULL);
	return (err_id);
}

// 22L
int	start_party(t_data *data)
{
	size_t	i;
	int		err_id;

	i = 0;
	err_id = OK;
	while (i < (size_t)data->pr.num_philos)
	{
    	data->philos[i].dine = &data->dine[i];
    	data->philos[i].last_eat_time = data->pr.start_time;
		data->philos[i].id = i + 1;
		data->philos[i].pr = &data->pr;
		data->philos[i].fork_r = &data->forks[i];
		if (i + 1 == (size_t)data->pr.num_philos)
			data->philos[i].fork_l = &data->forks[0];
		else
			data->philos[i].fork_l = &data->forks[i + 1];
		err_id = pthread_create(&data->threads[i], NULL, act, &data->philos[i]);
		if (err_id != OK)
			break ;
		i++;
	}
	return (err_id);
}

	// while (1)
// 24L
int	monitor_party(t_data *data)
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

// 13L
int	party_over(t_data *data)
{
	size_t	i;
	int		err_id;

	i = 0;
	while (i < (size_t)data->pr.num_philos)
	{
		err_id = pthread_join(data->threads[i], NULL);
		if (err_id != OK)
			break ;
		i++;
	}
    destroy_data(data);
	return (err_id);
}
