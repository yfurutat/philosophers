/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:51:34 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 21:36:11 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 20L
int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = prep_party(argc, argv, &data);
	if (ret != OK)
	{
		destroy_data(&data);
		return (ret);
	}
	ret = start_party(&data);
	if (ret != OK)
	{
		destroy_data(&data);
		return (ret);
	}
	usleep(1000);
	while (ret == OK)
		ret = monitor_party(&data);
	ret = party_over(&data);
	return (ret);
}

// __attribute__((destructor))
// static void	destructor()
// {
// 	system("sudo leaks -q philo");
// 	// system("leaks -q test.sh");
// }

// gettimeofday
// pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, 
// pthread_mutex_lock, pthread_mutex_unlock
// [timestamp_in_ms] X has taken a fork
// [timestamp_in_ms] X is eating
// [timestamp_in_ms] X is sleeping
// [timestamp_in_ms] X is thinking
// [timestamp_in_ms] X died

// #include "../includes/philo.h"

// int main()
// {
//     printf("errno: %d\n", errno);
//     errno = EINVAL;
//     printf("errno: %d\n", errno);
//     printf("EBUSY: %d\n", EBUSY);
//     printf("EINVAL: %d\n", EINVAL);
//     printf("OK: %d\n", OK);
//     printf("E_EMPTY: %d\n", E_EMPTY);
//     printf("E_INVALID_ARGC: %d\n", E_INVALID_ARGC);
//     return (0);
// }
