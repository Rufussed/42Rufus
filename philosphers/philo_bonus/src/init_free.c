/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/18 18:24:23 by rlane            ###   ########.fr       */
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
		if (pthread_mutex_init(&data->philos->last_eat_mutex, NULL) != 0)
			return (0);
		data->philos[i].data = data;
		i++;
	}
	return (1);
}

int	init_eat_sem(t_data *data)
{
	int	i;

	data->eat_sem = malloc(sizeof(sem_t) * data->num_p);
	i = 0;
	while (i < data->num_p)
	{
		data->eat_sem[i] = sem_open("/eat_semaphore", O_CREAT, 0644, 0);
		i++;
	}
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	if (!atoi(argv[1]))
		return (NULL);
	data = malloc(sizeof(t_data));
	data->num_p = atoi(argv[1]);
	data->tt_die = atoi(argv[2]);
	data->tt_eat = atoi(argv[3]);
	data->tt_sleep = atoi(argv[4]);
	if (argc == 6)
		data->max_eat = atoi(argv[5]);
	else
		data->max_eat = -1;
	data->end_sim_sem = sem_open("/end_sim_semaphore", O_CREAT, 0644, 0);
	if (data->end_sim_sem == SEM_FAILED)
	{
		perror("Failed to create end_sim semaphore");
		return (NULL);
	}
	data->forks_sem = sem_open("/forks_semaphore", O_CREAT, 0644, data->num_p);
	init_philos(data);
	init_eat_sem(data);
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->end_sim_sem != SEM_FAILED)
		{
			sem_close(data->end_sim_sem);
			sem_unlink("/end_sim_semaphore");
		}
		if (data->forks_sem != SEM_FAILED)
		{
			sem_close(data->forks_sem);
			sem_unlink("/forks_semaphore");
		}
		if (data->eat_sem)
		{
			i = 0;
			while (i < data->num_p)
			{
				sem_close(data->eat_sem[i]);
				sem_unlink("/eat_semaphore");
				i++;
			}
			free(data->eat_sem);
		}
		free(data);
	}
}

