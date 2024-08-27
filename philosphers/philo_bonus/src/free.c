/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/08/23 16:03:04 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_semaphores(t_data *data)
{
	if (data->end_sim_sem != SEM_FAILED)
		sem_close(data->end_sim_sem);
	if (data->forks_sem != SEM_FAILED)
		sem_close(data->forks_sem);
	if (data->philo_full_sem != SEM_FAILED)
		sem_close(data->philo_full_sem);
	if (data->waiter_sem != SEM_FAILED)
		sem_close(data->waiter_sem);
	sem_unlink("/waiter_semaphore");
	sem_unlink("/end_sim_semaphore");
	sem_unlink("/forks_semaphore");
	sem_unlink("/philo_full_semaphore");
}

void	free_data(t_data *data)
{
	int	i;

	if (data)
	{
		if (data->philos)
		{
			i = 0;
			while (i < data->num_p)
			{
				pthread_mutex_destroy(&data->philos[i].philo_mutex);
				i++;
			}
			free(data->philos);
		}
		close_semaphores(data);
		pthread_mutex_destroy(&data->end_sim_mutex);
		pthread_mutex_destroy(&data->philo_full_mutex);
		free(data);
	}
}

void	finish_threads_join(t_data *data)
{
	sem_post(data->end_sim_sem);
	sem_post(data->philo_full_sem);
	pthread_join(data->philos_full_thread, NULL);
	pthread_join(data->check_end_sim_thread, NULL);
}

