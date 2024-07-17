/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:20:32 by rlane             #+#    #+#             */
/*   Updated: 2024/07/17 12:35:54 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end_sim(t_data *data)
{
	int	result;
	// probably not needed without mutexes
	
	result = data->end_sim;
	
	return (result);
}

void	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (!check_end_sim(data))
		{
			
			if (get_time() - data->philos[i].last_eat > data->tt_die)
			{
				print_status(&data->philos[i], DIED);
				
				data->end_sim = 1;
				
				return ;
			}
			
		}
		i++;
	}
}

void	*death_watch(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(data->tt_die * 1000);
	while (!check_end_sim(data))
	{
		check_death(data);
		if (all_eaten_enough(data))
		{
			
			data->end_sim = 1;
			
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	init_death_watch(t_data *data)
{
	// make the death watch pocess
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
