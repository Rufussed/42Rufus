/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_eaten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/15 15:24:54 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*exit_error_null(char *msg)
{
	printf(RED "Error: %s\n\n" RESET, msg);
	return (NULL);
}

int	exit_error_zero(char *msg)
{
	printf(RED "Error: %s\n\n" RESET, msg);
	return (0);
}

int	all_eaten_enough(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (!eaten_enough(&data->philos[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

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
