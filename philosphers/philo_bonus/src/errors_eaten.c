/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_eaten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/18 18:50:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_mutex_lock(&data->philos[i].last_eat_mutex);
		if (!eaten_enough(&data->philos[i]))
		{
			pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->philos[i].last_eat_mutex);
		i++;
	}
	return (1);
}

int	eaten_enough(t_philo *philo)
{
	
	if (philo->data->max_eat == -1)
		return (0);
	if (philo->num_eat >= philo->data->max_eat)
		return (1);
	return (0);
}
