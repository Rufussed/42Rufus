/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/15 14:08:49 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eaten_enough(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (!eaten_enough(data->philos[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_end_sim(t_data *data)
{
	int	result;

	pthread_mutex_lock(data->end_sim_mutex);
	result = data->end_sim;
	pthread_mutex_unlock(data->end_sim_mutex);
	return (result);
}

void	*death_watch(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	usleep(data->tt_die * 1000);
	while (!check_end_sim(data))
	{
		i = 0;
		while (i < data->num_p)
		{
			if (!check_end_sim(data))
			{
				pthread_mutex_lock(&data->philos[i]->state_mutex);
				if (get_time() - data->philos[i]->last_eat > data->tt_die)
				{
					print_status(data->philos[i], DIED);
					pthread_mutex_unlock(&data->philos[i]->state_mutex);
					pthread_mutex_lock(data->end_sim_mutex);
					data->end_sim = 1;
					pthread_mutex_unlock(data->end_sim_mutex);
					return (NULL);
				}
				pthread_mutex_unlock(&data->philos[i]->state_mutex);
			}
			i++;
		}
		if (all_eaten_enough(data))
		{
			pthread_mutex_lock(data->end_sim_mutex);
			data->end_sim = 1;
			pthread_mutex_unlock(data->end_sim_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	init_death_watch(t_data *data)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, death_watch, data) != 0)
		return (exit_error_zero("Failed to create death watch thread"));
	data->death_watch_thread = thread;
	return (1);
}


int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 5 && argc != 6)
	{
		printf("\nParams: [num of philosphers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) num of times each must eat]\n\n");
		return (1);
	}
	data = init_data(argc, argv);
	if (!data)
		return (1);
	join_threads(data);
	free_data(data);
	return (0);
}
