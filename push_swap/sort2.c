/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:47:21 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 19:26:56 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_max_min_index(t_res *res)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*min;

	temp = res->stack_a;
	min = temp;
	while (temp)
	{
		if (temp->val < min->val)
			min = temp;
		temp = temp->next;
	}
	res->min_index_a = min->index;
	temp = res->stack_b;
	max = temp;
	if (!temp)
		return ;
	while (temp)
	{
		if (temp->val > max->val)
			max = temp;
		temp = temp->next;
	}
	res->max_index_b = max->index;
	return ;
}

void	index_stack(t_stack *stack, int count)
{
	t_stack	*temp;
	int		i;
	int		median;

	median = count / 2;
	temp = stack;
	i = 0;
	while (temp)
	{
		temp->index = i;
		if (i > median)
			temp->median = BELOW;
		else		
			temp->median = ABOVE;
		if (temp->median == ABOVE)
			temp->push_cost = i;
		if (temp->median == BELOW)
			temp->push_cost = count - i;
		temp = temp->next;
		i++;
	}
}

int	find_target_desc(t_stack *stack, int val)
{
	t_stack	*temp;
	int		i;
	int		target;
	int		min_diff;
	int		diff;

	temp = stack;
	i = 0;
	target = NONE;
	min_diff = INT_MAX;
	while (temp)
	{
		diff = val - temp->val;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = i;
		}
		temp = temp->next;
		i++;
	}
	return (target);
}

int	get_target_index_desc(int val, t_res *res)
{
	int	target;

	target = find_target_desc(res->stack_b, val);
	if (target == NONE)
		return (res->max_index_b);
	return (target);
}

// retrieve the stack node with the index i

t_stack	*get_stack_index(t_stack *stack, int i)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->index == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
