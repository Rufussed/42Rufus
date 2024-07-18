/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/18 18:52:23 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (!check_end_sim(data))
		{
			pthread_mutex_lock(&data->philos[i].last_eat_mutex);
			if (get_time() - data->philos[i].last_eat > data->tt_die)
			{
				pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
				print_status(&data->philos[i], DIED);
				sem_post(data->end_sim_sem);
				return ;
			}
			pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
		}
		i++;
	}
}

void	*get_last_eat_thread(void *argv)
{
	t_data	*data;
	int		i;

	data = (t_data *)argv;
	while (1)
	{
		i = 0;
		while (i < data->num_p)
		{
			if (sem_wait(data->eat_sem[i]) != 0)
			{
				sem_post(data->eat_sem[i]);
				pthread_mutex_lock(&data->philos[i].last_eat_mutex);
				data->philos[i].num_eat++;				
				data->philos[i].last_eat = get_time();
				pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
			}
			i++;
		}
		if (sem_wait(data->end_sim_sem) == 0)
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	*death_watch(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!check_end_sim(data))
	{
		check_death(data);
		if (all_eaten_enough(data))
		{
			set_end_sim(data);
			break ;
			//return (NULL);
		}
		usleep(1000);
	}
	usleep(1000);
	return (NULL);
}

int	init_death_watch(t_data *data)
{
	pthread_t	last_eat_thread;

	if (pthread_create(&last_eat_thread, NULL, get_last_eat_thread, data) != 0)
		return (0);
	death_watch(data);
	pthread_join(last_eat_thread, NULL);
	return (1);
}

void	create_process_loop(t_data *data)
{
	int		i;
	pid_t		pid;

	i = 0;
	while (i < data->num_p)
	{
		pid = fork();
		if (pid == 0)
		{
			//printf("Philosophers process fork\n");
			data->philos[i].pid = getpid();
			philo_routine(&data->philos[i]);
			exit(0);
		}
		else if (pid > 0)
		{
			data->philos[i].pid = pid;
			//printf("Philosophers process main\n");
		}
		i++;
	}
	usleep(data->tt_die * 1000);
	init_death_watch(data);
	i = 0;
	while (i < data->num_p)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 5 && argc != 6)
	{
		printf("\nParams: [num of philosphers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) num of times each must eat]\n\n");
		return (1);
	}

	data = init_data(argc, argv);
	if (!data)
		return (1);
	create_process_loop(data);
	free_data(data);
	return (0);
}
