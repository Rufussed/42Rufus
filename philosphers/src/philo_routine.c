/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/15 14:07:39 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->state_mutex);
	if (philo->data->max_eat == -1)
	{
		pthread_mutex_unlock(&philo->state_mutex);
		return (0);
	}
	if (philo->num_eat >= philo->data->max_eat)
	{
		pthread_mutex_unlock(&philo->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->state_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_end_sim(philo->data))
	{
		think(philo);
		eat(philo);
		if (eaten_enough(philo))
			break ;
		bedtime(philo);
	}

	return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	char	*colour;

	if (check_end_sim(philo->data))
		return ;
	pthread_mutex_lock(philo->data->print_mutex);
	colour = assign_colour(philo->id);
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msg);
	pthread_mutex_unlock(philo->data->print_mutex);
}

void	pick_up_forks(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&(philo->data->fork_mutex[philo->fork_left]));
		print_status(philo, FORK);
		pthread_mutex_lock(&(philo->data->fork_mutex[philo->fork_right]));
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&(philo->data->fork_mutex[philo->fork_right]));
		print_status(philo, FORK);
		pthread_mutex_lock(&(philo->data->fork_mutex[philo->fork_left]));
		print_status(philo, FORK);
	}
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->data->fork_mutex[philo->fork_left]));
	pthread_mutex_unlock(&(philo->data->fork_mutex[philo->fork_right]));
}

void	eat(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	pick_up_forks(philo);
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->state_mutex);
	print_status(philo, EAT);
	usleep(philo->data->tt_eat * 1000);
	put_down_forks(philo);
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	philo->num_eat++;
	pthread_mutex_unlock(&philo->state_mutex);
}

void	bedtime(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	print_status(philo, SLEEP);
	usleep(philo->data->tt_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	print_status(philo, THINK);
}

