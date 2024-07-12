/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/12 14:59:06 by rlane            ###   ########.fr       */
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
	if (philo->id % 2 == 0)
        usleep(4000);
	while (!philo->data->end_sim)
	{
		think(philo);
		eat(philo);
		if (eaten_enough(philo))
			break ;
		bedtime(philo);
	}

	return (NULL);
}

void	print_status(t_philo *philo, int msg)
{
	char	*msgs[5];
	char	*colour;

	if (philo->data->end_sim)
		return ;
	msgs[FORK] = "has taken a fork";
	msgs[EAT] = "is eating";
	msgs[SLEEP] = "is sleeping";
	msgs[THINK] = "is thinking";
	msgs[DIED] = "died";
	colour = assign_colour(philo->id);
	pthread_mutex_lock(philo->data->print_mutex);
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msgs[msg]);
	pthread_mutex_unlock(philo->data->print_mutex);
}

void	pick_up_forks(t_philo *philo)
{
	if (philo->data->end_sim)
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
	char	*colour;

	if (philo->data->end_sim)
		return ;
	colour = assign_colour(philo->id);
	pick_up_forks(philo);
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->state_mutex);
	print_status(philo, EAT);
	usleep(philo->data->tt_eat * 1000);
	put_down_forks(philo);
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->state_mutex);
	philo->num_eat++;
}

void	bedtime(t_philo *philo)
{
	if (philo->data->end_sim)
		return ;
	print_status(philo, SLEEP);
	usleep(philo->data->tt_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (philo->data->end_sim)
		return ;
	print_status(philo, THINK);
}

