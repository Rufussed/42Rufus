/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rlane             #+#    #+#             */
/*   Updated: 2024/08/28 17:18:39 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_bad_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

// nptr stands for number pointer (a string representing a num)
int	ft_atoi(const char *nptr)
{
	int	num;

	num = 0;
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num);
}

// time in milliseconds

long long	get_time(void)
{
	static long long	base_time;
	long long			current_time;
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	current_time = (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (base_time == 0)
		base_time = current_time;
	return (current_time - base_time);
}

int	check_bad_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("\nParams: [num of philosphers] [time to die] [time to eat]");
		printf(" [time to sleep] [(optional) num of times each must eat]\n\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (check_bad_chars(argv[i]))
		{
			printf("Error: bad argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

/*
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
		printf("Number of times eaten: %d\n", data->philos[i]->num_eat);
		printf("Last eaten at:\t%lld msecs\n", data->philos[i]->last_eat);
		printf("Dead:\t\t%d\n", data->philos[i]->dead);
		i++;
	}
}*/
