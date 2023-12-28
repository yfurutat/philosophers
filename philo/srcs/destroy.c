/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:45:29 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 21:32:11 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 11L
int	destroy_data(t_data *data)
{
	errno = 0;
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->threads)
			free(data->threads);
		if (data->forks)
			destroy_mutex_array(data->forks, (size_t)data->pr.num_philos);
		if (data->dine)
			destroy_mutex_array(data->dine, (size_t)data->pr.num_philos);
	}
	return (errno);
}

// 11L
void	destroy_mutex_array(pthread_mutex_t *ptr, size_t num)
{
	size_t	i;

	if (ptr == NULL)
		return ;
	i = 0;
	while (i < num)
	{
		errno = pthread_mutex_destroy(&ptr[i]);
		i++;
	}
	free(ptr);
}
