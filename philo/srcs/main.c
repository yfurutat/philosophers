/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:51:34 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/28 20:27:07 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 13L
int	cleanup(t_data *data)
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

// 22L
int	start(t_data *data)
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

// 11L
int	prep(int argc, char **argv, t_data *data)
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

// 20L
int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = prep(argc, argv, &data);
	if (ret != OK)
	{
		destroy_data(&data);
		return (ret);
	}
	ret = start(&data);
	if (ret != OK)
	{
		destroy_data(&data);
		return (ret);
	}
	usleep(1000);
	while (ret == OK)
		ret = monitor(&data);
	ret = cleanup(&data);
	return (ret);
}

// __attribute__((destructor))
// static void	destructor()
// {
// 	system("sudo leaks -q philo");
// 	// system("leaks -q test.sh");
// }
		// {
		// 	destroy_data(data);
		// 	return (err_id);
		// }
		// err_id = pthread_detach(data.threads[i]);
		// if (err_id)
		// {
		// 	destroy_data(&data);
		// 	return (-1);
		// }

// // 14L
// int	main(int argc, char **argv)
// {
// 	t_data	        data;
// 	int 	        ret;
// 	// size_t	        i;

//     // memset(&data, '\0', sizeof(t_data));
//     // ret = parse_args(argc, argv, &data.pr);
// 	// if (ret)
//     // {

// 	// 	return (-1);
//     // }
//     // ret = init(&data);
// 	// if (ret != OK)
// 	// {
// 	// 	destroy_data(&data);
// 	// 	return (-1);
// 	// }
//     // data.pr.start_time = get_time(NULL);
//     // if (ret != OK)
// 	// {
// 	// 	destroy_data(&data);
// 	// 	return (-1);
// 	// }
// 	ret = prep(argc, argv, &data);
// 	if (ret != OK)
// 		return (ret);
// 	ret = start(&data);
// 	if (ret != OK)
// 		return (ret);
// 	// i = 0;
// 	// while (i < (size_t)data.pr.num_philos)
// 	// {
//     // 	data.philos[i].dine = &data.dine[i];
//     // 	data.philos[i].last_eat_time = data.pr.start_time;
// 	// 	data.philos[i].id = i + 1;
// 	// 	data.philos[i].pr = &data.pr;
// 	// 	data.philos[i].fork_r = &data.forks[i];
// 	// 	if (i + 1 == (size_t)data.pr.num_philos)
// 	// 		data.philos[i].fork_l = &data.forks[0];
// 	// 	else
// 	// 		data.philos[i].fork_l = &data.forks[i + 1];
// 	// 	ret = pthread_create(&data.threads[i], NULL, act, &data.philos[i]);
// 	// 	if (ret)
// 	// 	{
// 	// 		destroy_data(&data);
// 	// 		return (-1);
// 	// 	}
// 	// 	// ret = pthread_detach(data.threads[i]);
// 	// 	// if (ret)
// 	// 	// {
// 	// 	// 	destroy_data(&data);
// 	// 	// 	return (-1);
// 	// 	// }
// 	// 	i++;
// 	// }
// 	usleep(500);
// 	// while (1)
// 	// {
// 	// 	if (monitor(&data) != OK)
// 	// 		break ;
// 	// }
// 	while (ret == OK)
// 		ret = monitor(&data);
// 	ret = cleanup(&data);
// 	// i = 0;
// 	// while (i < (size_t)data.pr.num_philos)
// 	// {
// 	// 	ret = pthread_join(data.threads[i], NULL);
// 	// 	if (ret)
// 	// 	{
// 	// 		destroy_data(&data);
// 	// 		return (-1);
// 	// 	}
// 	// 	i++;
// 	// }
//     // destroy_data(&data);
// 	return (ret);
// }
		// pthread_detach(philosophers[i]);
		// printf("%zd\n", i);
	    // pthread_create(&philosophers[i], NULL, void *(*start_routine)(void *), void *arg);

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// // The function to be executed by the thread
// void *PrintHello(void *threadid) {
//     long tid;
//     tid = (long)threadid;
//     printf("Hello from thread %ld\n", tid);
//     // pthread_exit(NULL);
// 	return (NULL);
// }

// int main() {
//     pthread_t threads[2];
//     int rc;
//     long i;

//     for(i = 0; i < 2; i++) {
//         printf("In main: creating thread %ld\n", i);
//         rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
//         if (rc) {
//             printf("ERROR; return code from pthread_create() is %d\n", rc);
//             exit(-1);
//         }
//     }

//     // Wait for the threads to finish
//     for (i = 0; i < 2; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     // pthread_exit(NULL);
// }
// int	main(void)
	// printf("hello, world!\n");


		// pthread_create(&threads[i], NULL, act, &philos[i]);
		// printf("%zd\n", i);
        // pthread_mutex_init(philos->fork_l, NULL);

    // memset(threads, '\0', num);
    // memset(forks, '\0', num);

		// printf("%zd\n", i);

// gettimeofday
// pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, 
// pthread_mutex_lock, pthread_mutex_unlock

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
