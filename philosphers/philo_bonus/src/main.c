/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/25 18:16:03 by rlane            ###   ########.fr       */
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
		sem_wait(data->philo_full_sem);
		i++;
	}
	set_end_sim(data);
	return (NULL);
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
			data->philos[i].pid = pid;
		i++;
	}
	pthread_create(&data->philos_full_thread, NULL,	philos_full, data);
	i = 0;
	while (i < data->num_p)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
	finish_threads_join(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: %s num_philos time_to_die time_to_eat time_to_sleep ",
			argv[0]);
		printf("num_times_philo_must_eat\n");
		return (1);
	}
	data = init_data(argc, argv);
	if (!data)
		return (1);
	create_process_loop(data);
	free_data(data);
	return (0);
}
