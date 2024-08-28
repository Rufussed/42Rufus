/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rlane             #+#    #+#             */
/*   Updated: 2024/08/28 18:49:10 by rlane            ###   ########.fr       */
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

char	*assign_colour(int id)
{
	if (id % 10 == 0)
		return (ORANGE);
	else if (id % 9 == 0)
		return (YELLOW);
	else if (id % 8 == 0)
		return (GREEN);
	else if (id % 7 == 0)
		return (CYAN);
	else if (id % 6 == 0)
		return (BLUE);
	else if (id % 5 == 0)
		return (PURPLE);
	else if (id % 4 == 0)
		return (BOLD_ORANGE);
	else if (id % 3 == 0)
		return (BOLD_YELLOW);
	else if (id % 2 == 0)
		return (BOLD_GREEN);
	else
		return (BOLD_BLUE);
}
