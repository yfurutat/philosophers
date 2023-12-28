/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:45:29 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 18:18:36 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	}
	return (errno);
}

// void	free_map(char **map)
// {
// 	size_t	i;

// 	if (!map)
// 		return ;
// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		map[i] = NULL;
// 		i++;
// 	}
// 	free(map);
// }
	// free_map(data->map);
		// if ((data->img_p).img_ptr)
