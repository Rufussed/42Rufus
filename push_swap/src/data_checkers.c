/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:19:37 by rlane             #+#    #+#             */
/*   Updated: 2024/07/05 18:24:04 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_repeats(t_res *res, int val)
{
	t_stack	*temp;

	temp = res->stack_a;
	while (temp)
	{
		if (temp->val == val)
			exit_error(res);
		temp = temp->next;
	}
}

int	check_sign_range(t_res *res, long val, int sign)
{
	val = (val * sign);
	if (val > INT_MAX || val < INT_MIN)
		exit_error(res);
	return ((int)val);
}

int	check_atoi(const char *str, t_res *res)
{
	int		sign;
	int		i;
	long	val;

	val = 0;
	sign = 1;
	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		exit_error(res);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error(res);
		val = val * 10 + (str[i] - '0');
		i++;
	}
	val = check_sign_range(res, val, sign);
	check_repeats(res, val);
	return (val);
}

int	stack_is_sorted(t_stack *node)
{
	while (node->next)
	{
		if (node->val > node->next->val)
			return (0);
		node = node->next;
	}
	return (1);
}
