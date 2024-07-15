/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/15 14:00:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int		i;
	int		i_loop;

	data->philos = malloc(sizeof(t_philo) * data->num_p);
	i = 0;
	while (i < data->num_p)
	{
		i_loop = i - 1;
		if (i_loop < 0)
			i_loop = data->num_p - 1;
		data->philos[i] = malloc(sizeof(t_philo));
		data->philos[i]->id = i + 1;
		data->philos[i]->num_eat = 0;
		data->philos[i]->last_eat = get_time();
		data->philos[i]->fork_left = i;
		data->philos[i]->fork_right = i_loop;
		data->philos[i]->data = data;
		if (pthread_mutex_init(&data->philos[i]->state_mutex, NULL) != 0)
			return (exit_error_zero("Failed to init mutex"));
		if (pthread_create(&(data->philos[i]->thread), NULL, philo_routine,
				data->philos[i]) != 0)
			return (exit_error_zero("Failed to create thread for philosopher"));
		i++;
	}
	return (1);
}

int	init_mutexes(t_data *data)
{
	int	i;

	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_p);
	data->end_sim_mutex = malloc(sizeof(pthread_mutex_t));
	data->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->fork_mutex || !data->end_sim_mutex || !data->print_mutex)
		return (exit_error_zero("Failed to allocate memory for mutexes"));
	i = 0;
	while (i < data->num_p)
	{
		if (pthread_mutex_init(&(data->fork_mutex[i]), NULL) != 0)
			return (exit_error_zero("Failed to init mutex"));
		i++;
	}
	if (pthread_mutex_init(data->end_sim_mutex, NULL) != 0)
		return (exit_error_zero("Failed to init mutex"));
	if (pthread_mutex_init(data->print_mutex, NULL) != 0)
		return (exit_error_zero("Failed to init mutex"));
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->num_p = atoi(argv[1]);
	data->tt_die = atoi(argv[2]);
	data->tt_eat = atoi(argv[3]);
	data->tt_sleep = atoi(argv[4]);
	if (argc == 6)
		data->max_eat = atoi(argv[5]);
	else
		data->max_eat = -1;
	data->end_sim = 0;
	if (!(init_mutexes(data) && init_philos(data) && init_death_watch(data)))
	{
		return (NULL);
	}
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		pthread_mutex_destroy(&(data->fork_mutex[i]));
		pthread_mutex_destroy(&data->philos[i]->state_mutex);
		i++;
	}
	while (i < data->num_p)
	{
		free(data->philos[i]);
		i++;
	}
	pthread_mutex_destroy(data->end_sim_mutex);
	pthread_mutex_destroy(data->print_mutex);
	free(data->end_sim_mutex);
	free(data->philos);
	free(data->fork_mutex);
	free(data->print_mutex);
	free(data);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (pthread_join(data->philos[i]->thread, NULL) != 0)
			return (exit_error_zero("Failed to join thread"));
		i++;
	}
	if (pthread_join(data->death_watch_thread, NULL) != 0)
		exit_error_zero("Failed to join thread");
	return (1);
}


