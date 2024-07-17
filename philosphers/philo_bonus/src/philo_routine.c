/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/17 12:50:19 by rlane            ###   ########.fr       */
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
		if (eaten_enough(philo))
			break ;
		
		bedtime(philo);
	}
	return (NULL);
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
		sem_post(philo->data->forks_sem);
		philo->data->end_sim = 1;
		return ;
	}
	philo->last_eat = get_time();
	print_status(philo, EAT);
	usleep(philo->data->tt_eat * 1000);
	philo->last_eat = get_time();
	sem_post(philo->data->forks_sem);
	sem_post(philo->data->forks_sem);
	philo->num_eat++;
}

void	bedtime(t_philo *philo)
{
	if (check_end_sim(philo->data))
		return ;
	print_status(philo, SLEEP);
	usleep(philo->data->tt_sleep * 1000);
}

void	print_status(t_philo *philo, char *msg)
{
	char	*colour;

	if (check_end_sim(philo->data))
		return ;
	colour = assign_colour(philo->id);
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msg);
}
