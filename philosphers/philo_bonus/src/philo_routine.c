/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:55:39 by rlane             #+#    #+#             */
/*   Updated: 2024/08/28 19:47:34 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	pthread_t		check_starvation_thread;

	philo = (t_philo *)arg;
	init_check_end_sim_thread(philo->data);
	pthread_create(&check_starvation_thread, NULL, check_starvation, philo);
	while (!check_end_sim(philo)) 
	{
		print_status(philo, THINK);
		usleep(1000);
		eat(philo);
		if (eaten_enough(philo) || philo->data->num_p == 1)
			break ;
		print_status(philo, SLEEP);
		usleep(philo->data->tt_sleep * 1000);
	}
	pthread_join(check_starvation_thread, NULL);
	pthread_join(philo->data->check_end_sim_thread, NULL);
	free_data(philo->data);
	return (NULL);
}

void	pick_up_forks(t_philo *philo)
{
	if (check_end_sim(philo))
		return ;
	if (philo->data->num_p == 1)
	{
		sem_wait(philo->data->forks_sem);
		print_status(philo, FORK);
		return ;
	}
	sem_wait(philo->data->waiter_sem);
	sem_wait(philo->data->forks_sem);
	print_status(philo, FORK);
	usleep(1000);
	sem_wait(philo->data->forks_sem);
	print_status(philo, FORK);
	usleep(1000);
}

void	eat(t_philo *philo)
{
	if (check_end_sim(philo))
		return ;
	pick_up_forks(philo);
	if (philo->data->num_p == 1)
	{
		usleep(philo->data->tt_die * 1000);
		print_status(philo, DIED);
		sem_post(philo->data->end_sim_sem);
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
	sem_post(philo->data->waiter_sem);
}

void	print_status(t_philo *philo, char *msg)
{
	char	*colour;

	colour = assign_colour(philo->id);
	if (check_end_sim(philo))
		return ;
	printf("%s%lld %d %s\n" RESET, colour, get_time(), philo->id, msg);
}
