/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/25 18:18:18 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end_sim_data(t_data *data)
{
	int	end;

	pthread_mutex_lock(&data->end_sim_mutex);
	end = data->end_sim;
	pthread_mutex_unlock(&data->end_sim_mutex);
	return (end);
}

void	*check_starvation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_end_sim(philo))
	{
		pthread_mutex_lock(&philo->philo_mutex);
		if (get_time() - philo->last_eat > philo->data->tt_die)
		{
			pthread_mutex_unlock(&philo->philo_mutex);
			print_status(philo, DIED);
			set_end_sim(philo->data);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->philo_mutex);
		usleep(1000);
	}
	return (NULL);
}

void	*check_end_sim_sem(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (sem_wait(data->end_sim_sem) == 0)
		{
			sem_post(data->end_sim_sem);
			pthread_mutex_lock(&data->end_sim_mutex);
			data->end_sim = 1;
			pthread_mutex_unlock(&data->end_sim_mutex);
			break ;
		}
		usleep(1000); // 1ms
	}
	return (NULL);
}

int	check_end_sim(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->data->end_sim_mutex);
	end = philo->data->end_sim;
	pthread_mutex_unlock(&philo->data->end_sim_mutex);
	return (end);
}

// sets the end_sim semaphore to zero
void	set_end_sim(t_data *data)
{
	sem_post(data->end_sim_sem);
}
