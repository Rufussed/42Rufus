/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:47:21 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 18:05:50 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_asc(t_stack *stack, int val)
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
		diff = temp->val - val;
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

int	get_target_index_asc(int val, t_res *res)
{
	int	target;

	target = find_target_asc(res->stack_a, val);
	if (target == NONE)
		return (res->min_index_a);
	return (target);
}

void	set_full_cost_b(t_res *res)
{
	t_stack	*b;
	t_stack	*a;
	t_stack	*target;

	b = res->stack_b;
	a = res->stack_a;
	while (a)
	{
		target = get_stack_index(a, b->target);
		if (b->median != target->median)
			b->full_cost = b->push_cost + target->push_cost;
		else
			b->full_cost = b->push_cost 
				+ ft_abs(b->push_cost - target->push_cost);
		b = b->next;
	}
}

void	pa_ascending(t_res *res)
{
	int		push_ind;
	t_stack	*target;
	t_stack	*temp;

	push_ind = find_cheapest_push(res->stack_b);
	temp = get_stack_index(res->stack_b, push_ind);
	target = get_stack_index(res->stack_a, temp->target);
	rotat_stacks_synched(res, temp, target);
	rotate_stack_a(res, temp->median, temp->push_cost);
	rotate_stack_b(res, target->median, target->push_cost);
	pa(res);
}

void	prepare_stack_b(t_res *res)
{
	t_stack	*temp;

	index_stack(res->stack_a, res->count_a);
	index_stack(res->stack_b, res->count_b);
	set_max_min_index(res);
	temp = res->stack_b;
	while (temp)
	{
		temp->target = get_target_index_asc(temp->val, res);
		temp = temp->next;
	}
	set_full_cost_b(res);
	res->print = PRINT;
	print_list_vals(res);
	res->print = NO_PRINT;
	return ;
}
