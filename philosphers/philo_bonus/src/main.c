/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/24 18:27:47 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!check_end_sim(data))
	{
		if (data->philos_full >= data->num_p)
		{
			set_end_sim(data);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

int	init_monitor(t_data *data)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitor, data) != 0)
		return (0);
	pthread_join(monitor_thread, NULL);
	return (1);
}


void	create_process_loop(t_data *data)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < data->num_p)
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
	}
	init_monitor(data);
	i = -1;
	while (++i < data->num_p)
		waitpid(data->philos[i].pid, NULL, 0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: %s num_philos time_to_die time_to_eat time_to_sleep ",
			argv[0]);
		printf("[num_times_each_philo_must_eat]\n");
		return (1);
	}
	data = init_data(argc, argv);
	if (!data)
		return (1);
	create_process_loop(data);
	free_data(data);
	return (0);
}
