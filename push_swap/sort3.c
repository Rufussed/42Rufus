/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:47:21 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 18:05:35 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	set_full_cost_a(t_res *res)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*target;

	a = res->stack_a;
	b = res->stack_b;
	while (a)
	{
		target = get_stack_index(b, a->target);
		if (a->median != target->median)
			a->full_cost = a->push_cost + target->push_cost;
		else
			a->full_cost = a->push_cost 
				+ ft_abs(a->push_cost - target->push_cost);
		a = a->next;
	}
}

void	prepare_stack_a(t_res *res)
{
	t_stack	*temp;

	index_stack(res->stack_a, res->count_a);
	index_stack(res->stack_b, res->count_b);
	set_max_min_index(res);
	temp = res->stack_a;
	while (temp)
	{
		temp->target = get_target_index_desc(temp->val, res);
		temp = temp->next;
	}
	set_full_cost_a(res);
	res->print = PRINT;
	print_list_vals(res);
	res->print = NO_PRINT;
	return ;
}
