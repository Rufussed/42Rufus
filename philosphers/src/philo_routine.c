/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/11 19:32:34 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	pick_up_forks(t_philo *philo)
{
	char	*colour;

	colour = assign_colour(philo->id);
	if (philo->id % 2)
	{
		pthread_mutex_lock(&(philo->data->fork_lock[philo->fork_left]));
		printf("%s%lld Philosopher %d has taken a fork\n" RESET, colour,
			get_time(), philo->id);
		pthread_mutex_lock(&(philo->data->fork_lock[philo->fork_right]));
		printf("%s%lld Philosopher %d has taken a fork\n" RESET, colour,
			get_time(), philo->id);
	}
	else
	{
		pthread_mutex_lock(&(philo->data->fork_lock[philo->fork_right]));
		printf("%s%lld Philosopher %d has taken a fork\n" RESET, colour,
			get_time(), philo->id);
		pthread_mutex_lock(&(philo->data->fork_lock[philo->fork_left]));
		printf("%s%lld Philosopher %d has taken a fork\n" RESET, colour,
			get_time(), philo->id);
	}
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->data->fork_lock[philo->fork_left]));
	pthread_mutex_unlock(&(philo->data->fork_lock[philo->fork_right]));
}

void	eat(t_philo *philo)
{
	char*colour;

	colour = assign_colour(philo->id);
	pick_up_forks(philo);
	printf("%s%lld Philosopher %d is eating\n" RESET, assign_colour(philo->id),
		get_time(), philo->id);
	usleep(philo->data->tte * 1000);
	put_down_forks(philo);
	philo->last_eat = get_time();
	philo->num_e++;	
}

void	bedtime(t_philo *philo)
{
	char	*colour;

	colour = assign_colour(philo->id);
	printf("%s%lld Philosopher %d is sleeping\n" RESET, colour,
		get_time(),	philo->id);
	usleep(philo->data->tts * 1000);
}

void	think(t_philo *philo)
{
	char	*colour;

	colour = assign_colour(philo->id);
	printf("%s%lld Philosopher %d is thinking\n" RESET, colour,
		get_time(),	philo->id);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->num_e == -1 || philo->num_e < philo->data->num_e)
	{
		think(philo);
		eat(philo);
		bedtime(philo);
	}
	return (NULL);
}

int	join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (pthread_join(data->philos[i]->thread, NULL) != 0)
			exit_error("Failed to join thread for philosopher");
		i++;
	}
	return (1);
}
