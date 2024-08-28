/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/08/28 19:22:56 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_full(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->num_p && !check_end_sim_data(data))
	{
		if (check_end_sim_data(data))
			break ;
		sem_wait(data->philo_full_sem);
		i++;
	}
	sem_post(data->end_sim_sem);
	return (NULL);
}

void	join_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
}

void	create_process_loop(t_data *data)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < data->num_p)
	{
		pid = fork();
		if (pid == 0)
		{
			data->philos[i].pid = getpid();
			philo_routine(&data->philos[i]);
			exit(0);
		}
		else if (pid > 0)
		{
			data->philos[i].pid = pid;
			usleep(1000);
		}
		i++;
	}
	pthread_create(&data->philos_full_thread, NULL, philos_full, data);
	join_processes(data);
	finish_threads_join(data);
}

int	check_bad_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("\nParams: [num of philosphers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) num of times each must eat]\n\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (check_bad_chars(argv[i]))
		{
			printf("Error: bad argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_bad_args(argc, argv))
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	create_process_loop(data);
	free_data(data);
	return (0);
}
