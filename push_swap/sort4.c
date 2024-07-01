/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:12:18 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 17:24:29 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_push(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*cheapest;
	int		min_cost;

	temp = stack;
	cheapest = temp;
	min_cost = temp->full_cost;
	while (temp)
	{
		if (temp->full_cost < min_cost)
		{
			min_cost = temp->full_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest->index);
}

void	rotate_stack_a(t_res *res, int temp_median, int p_cost_a)
{
	if (temp_median == ABOVE)
	{
		while (p_cost_a > 0)
		{
			ra(res);
			p_cost_a--;
		}
	}
	if (temp_median == BELOW)
	{
		while (p_cost_a > 0)
		{
			rra(res);
			p_cost_a--;
		}
	}
}

void	rotate_stack_b(t_res *res, int target_median, int p_cost_b)
{
	if (target_median == ABOVE)
	{
		while (p_cost_b > 0)
		{
			rb(res);
			p_cost_b--;
		}
	}
	if (target_median == BELOW)
	{
		while (p_cost_b > 0)
		{
			rrb(res);
			p_cost_b--;
		}
	}
}

void	rotat_stacks_synched(t_res *res, t_stack *temp, t_stack *target)
{
	if (temp->median == ABOVE && target->median == ABOVE)
	{
		while (temp->push_cost > 0 && target->push_cost > 0)
		{
			rr(res);
			temp->push_cost--;
			target->push_cost--;
		}
	}
	if (temp->median == BELOW && target->median == BELOW)
	{
		while (temp->push_cost > 0 && target->push_cost > 0)
		{
			rrr(res);
			temp->push_cost--;
			target->push_cost--;
		}
	}
}

void	pb_descending(t_res *res)
{
	int		push_ind;
	t_stack	*target;
	t_stack	*temp;

	push_ind = find_cheapest_push(res->stack_a);
	temp = get_stack_index(res->stack_a, push_ind);
	target = get_stack_index(res->stack_b, temp->target);
	rotat_stacks_synched(res, temp, target);
	rotate_stack_a(res, temp->median, temp->push_cost);
	rotate_stack_b(res, target->median, target->push_cost);
	pb(res);
}
