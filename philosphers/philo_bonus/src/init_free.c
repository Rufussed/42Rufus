/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/17 12:51:56 by rlane            ###   ########.fr       */
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
		data->philos[i].data = data;
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
	data->end_sim = 0;
	data->forks_sem = sem_open("/forks_semaphore", O_CREAT, 0644, data->num_p);
	if (data->forks_sem == SEM_FAILED)
	{
		free_data(data);
		return (NULL);
	}
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->forks_sem != SEM_FAILED)
		{
			sem_close(data->forks_sem);
			sem_unlink("/forks_semaphore");
		}
		free(data);
	}
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		// close processes?
	}
	// close deathwatch process?
	return (1);
}
