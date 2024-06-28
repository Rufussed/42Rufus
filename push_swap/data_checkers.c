/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:19:37 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 11:07:00 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_repeats(t_res *res, int value)
{
	t_stack	*temp;

	temp = res->stack_a;
	while (temp)
	{
		if (temp->value == value)
			exit_error("there are duplicates", res);
		temp = temp->next;
	}
}

int	check_atoi(const char *str, t_res *res)
{
	int		sign;
	int		i;
	long	value;

	value = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error("some arguments aren't integers", res);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	value = (value * sign);
	if (value > INT_MAX || value < INT_MIN)
		exit_error("some arguments are bigger than an integer", res);
	check_repeats(res, value);
	return ((int)value);
}

int	stack_is_sorted(t_stack *node)
{
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
