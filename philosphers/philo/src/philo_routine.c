/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/18 13:46:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (NULL);
}

void	pick_up_forks(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	if (philo->data->num_p == 1)
	{
		pthread_mutex_lock(&(philo->data->fork_mutex[philo->fork_left]));
		print_status(philo, FORK);
		return ;
	}
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

void	eat(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	pick_up_forks(philo);
	if (philo->data->num_p == 1)
	{
		usleep(philo->data->tt_die * 1000);
		print_status(philo, DIED);
		pthread_mutex_lock(&philo->data->end_sim_mutex);
		philo->data->end_sim = 1;
		pthread_mutex_unlock(&philo->data->end_sim_mutex);
		pthread_mutex_unlock(&(philo->data->fork_mutex[philo->fork_left]));
		return ;
	}
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->state_mutex);
	print_status(philo, EAT);
	usleep(philo->data->tt_eat * 1000);
	pthread_mutex_unlock(&(philo->data->fork_mutex[philo->fork_left]));
	pthread_mutex_unlock(&(philo->data->fork_mutex[philo->fork_right]));
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_eat = get_time();
	philo->num_eat++;
	pthread_mutex_unlock(&philo->state_mutex);
}

void	print_status(t_philo *philo, char *msg)
{
	char	*colour;

	colour = assign_colour(philo->id);
	if (check_end_sim(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}