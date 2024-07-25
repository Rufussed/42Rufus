/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_eaten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/24 17:34:59 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error_zero(char *msg)
{
	printf(RED "Error: %s\n\n" RESET, msg);
	return (0);
}

void *philo_full(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	if (sem_wait(data->philo_full_sem) == 0)
	{
		sem_post(data->philo_full_sem);
		pthread_mutex_lock(&data->philo_full_mutex);
		data->philos_full++;
		pthread_mutex_unlock(&data->philo_full_mutex);
	}
	return (NULL);
}

int	eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->data->max_eat == -1)
	{
		pthread_mutex_unlock(&philo->philo_mutex);
		return (0);
	}
	if (philo->num_eat >= philo->data->max_eat)
	{
		sem_post(philo->data->philo_full_sem);
		pthread_mutex_unlock(&philo->philo_mutex);
		return (1);
	}
	return (0);
}
