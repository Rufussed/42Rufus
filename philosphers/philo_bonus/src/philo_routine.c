/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/24 18:17:23 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	}
	return (NULL);
}

int	check_end_sim(t_data *data)
{
	int	end;

	pthread_mutex_lock(&data->end_sim_mutex);
	end = data->end_sim;
	pthread_mutex_unlock(&data->end_sim_mutex);
	return (end);
}

// sets the end_sim semaphore to zero
void	set_end_sim(t_data *data)
{
	sem_post(data->end_sim_sem);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_end_sim(philo->data))
	{
		print_status(philo, THINK);
		eat(philo);
		if (eaten_enough(philo) || check_end_sim(philo->data))
			break ;
		print_status(philo, SLEEP);
		usleep(philo->data->tt_sleep * 1000);
	}
	free_data(philo->data);
	exit(0);
}

void	pick_up_forks(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	if (philo->data->num_p == 1)
	{
		sem_wait(philo->data->forks_sem);
		print_status(philo, FORK);
		return ;
	}
	sem_wait(philo->data->forks_sem);
	print_status(philo, FORK);
	sem_wait(philo->data->forks_sem);
	print_status(philo, FORK);
}

void	eat(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	pick_up_forks(philo);
	if (philo->data->num_p == 1)
	{
		usleep(philo->data->tt_die * 1000);
		print_status(philo, DIED);
		set_end_sim(philo->data);
		sem_post(philo->data->forks_sem);
		return ;
	}
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_eat = get_time();
	philo->num_eat++;
	pthread_mutex_unlock(&philo->philo_mutex);
	usleep(philo->data->tt_eat * 1000);
	sem_post(philo->data->forks_sem);
	sem_post(philo->data->forks_sem);
}

void	print_status(t_philo *philo, char *msg)
{
	char	*colour;

	colour = assign_colour(philo->id);
	if (check_end_sim(philo->data))
		return ;
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msg);
}
