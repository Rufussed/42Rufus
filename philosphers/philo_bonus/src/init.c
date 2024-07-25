/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/25 18:00:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int		i;
	int		i_loop;

	data->philos = malloc(sizeof(t_philo) * data->num_p);
	i = 0;
	while (i < data->num_p)
	{
		i_loop = i - 1;
		if (i_loop < 0)
			i_loop = data->num_p - 1;
		data->philos[i].id = i + 1;
		data->philos[i].num_eat = 0;
		data->philos[i].last_eat = get_time();
		pthread_mutex_init(&data->philos[i].philo_mutex, NULL);
		data->philos[i].data = data;
		i++;
	}
	return (1);
}

int	init_check_end_sim_thread(t_data *data)
{
	data->end_sim = 0;

	pthread_create(&data->check_end_sim_thread, NULL, check_end_sim_sem, data);
	return (1);
}

static int	init_semaphores(t_data *data)
{
	sem_unlink("/end_sim_semaphore");
	sem_unlink("/forks_semaphore");
	sem_unlink("/philo_full_semaphore");
	data->forks_sem = sem_open("/forks_semaphore", O_CREAT | O_EXCL, 0644,
			data->num_p);
	data->end_sim_sem = sem_open("/end_sim_semaphore", O_CREAT | O_EXCL,
			0644, 1);
	sem_wait(data->end_sim_sem);
	data->philo_full_sem = sem_open("/philo_full_semaphore", O_CREAT | O_EXCL,
			0644, 1);
	sem_wait(data->philo_full_sem);
	if (data->end_sim_sem == SEM_FAILED || data->forks_sem == SEM_FAILED
		|| data->philo_full_sem == SEM_FAILED)
		return (0);
	return (1);
}

static int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->end_sim_mutex, NULL) != 0
		|| pthread_mutex_init(&data->philo_full_mutex, NULL) != 0)
		return (0);
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_p = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->philos_full = 0;
	data->end_sim = 0;
	if (!init_mutexes(data) || !init_semaphores(data)
		|| !init_philos(data) || !init_check_end_sim_thread(data))
	{
		free_data(data);
		return (NULL);
	}
	return (data);
}

