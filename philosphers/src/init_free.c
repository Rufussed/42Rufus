/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/12 13:16:50 by rlane            ###   ########.fr       */
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

int	init_philos(t_data *data)
{
	int		i;
	int		i_loop;

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
		data->philos[i]->dead = 0;
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

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (pthread_mutex_init(&(data->fork_mutex[i]), NULL) != 0)
			return (exit_error_zero("Failed to init mutex"));
		i++;
	}
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
	data->end_sim = 0;
	if (argc == 6)
		data->max_eat = atoi(argv[5]);
	else
		data->max_eat = -1;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_p);
	if (!init_forks(data))
		return (NULL);
	data->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->print_mutex, NULL) != 0)
		return (exit_error_null("Failed to init mutex"));
	data->philos = malloc(sizeof(t_philo) * data->num_p);
	if (!init_philos(data))
		return (NULL);
	if (!init_death_watch(data))
		return (NULL);
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		free(data->philos[i]);
		pthread_mutex_destroy(&(data->fork_mutex[i]));
		pthread_mutex_destroy(&data->philos[i]->state_mutex);
		i++;
	}
	pthread_mutex_destroy(data->print_mutex);
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


