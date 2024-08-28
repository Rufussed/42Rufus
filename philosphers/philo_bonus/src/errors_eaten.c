/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_eaten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/08/27 20:43:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error_zero(char *msg)
{
	printf(RED "Error: %s\n\n" RESET, msg);
	return (0);
}

int	eaten_enough(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->data->max_eat != -1 && philo->num_eat >= philo->data->max_eat)
		result = 1;
	pthread_mutex_unlock(&philo->philo_mutex);
	if (result)
		sem_post(philo->data->philo_full_sem);
	return (result);
}
