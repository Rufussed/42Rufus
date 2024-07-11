/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/11 18:44:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*exit_error(char *msg)
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
		data->philos[i]->num_e = 0;
		data->philos[i]->last_eat = get_time();
		data->philos[i]->fork_left = i;
		data->philos[i]->fork_right = i_loop;
		data->philos[i]->dead = 0;
		data->philos[i]->data = data;
		if (pthread_create(&(data->philos[i]->thread), NULL, philo_routine,
				data->philos[i]) != 0)
				exit_error("Failed to create thread for philosopher");
		i++;
	}
	return (1);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	data->num_p = atoi(argv[1]);
	data->ttd = atoi(argv[2]);
	data->tte = atoi(argv[3]);
	data->tts = atoi(argv[4]);
	if (argc == 6)
		data->num_e = atoi(argv[5]);
	else
		data->num_e = -1;
	data->philos = malloc(sizeof(t_philo) * data->num_p);
	if (!init_philos(data))
		return (NULL);
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * data->num_p);
	data->print_lock = malloc(sizeof(pthread_mutex_t) * data->num_p);
	i = 0;
	while (i < data->num_p)
	{
		if (pthread_mutex_init(&(data->fork_lock[i]), NULL) != 0)
			return (exit_error("Failed to init mutex"));
		if (pthread_mutex_init(&(data->print_lock[i]), NULL) != 0)
			return (exit_error("Failed to init mutex"));
		i++;
	}
	return (data);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		free(data->philos[i]);
		pthread_mutex_destroy(&(data->fork_lock[i]));
		i++;
	}
	free(data->philos);
	free(data->fork_lock);
	free(data->print_lock);
	free(data);
}

void	print_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		printf(YELLOW "Philosopher %d\n" RESET, data->philos[i]->id);
		printf("index:\t\t%d\n", i);
		printf("Fork left:\t%d\n", data->philos[i]->fork_left);
		printf("Fork right:\t%d\n", data->philos[i]->fork_right);
		printf("Number of times eaten: %d\n", data->philos[i]->num_e);
		printf("Last eaten at:\t%lld msecs\n", data->philos[i]->last_eat);
		printf("Dead:\t\t%d\n", data->philos[i]->dead);
		i++;
	}
}


