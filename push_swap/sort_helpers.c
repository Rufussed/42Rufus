/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:47:21 by rlane             #+#    #+#             */
/*   Updated: 2024/06/30 17:16:19 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_max_min_node(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*min;	

	temp = stack;
	max = temp;
	min = temp;
	while (temp)
	{
		if (temp->val > max->val)
			max = temp;
		if (temp->val < min->val)
			min = temp;
		temp = temp->next;
	}
	max->max = 1;
	min->min = 1;
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
		if (temp->median == ABOVE)
			temp->push_cost = i;
		if (temp->median == BELOW)
			temp->push_cost = count - i;
		temp = temp->next;
		i++;
	}
}

int get_target_index_desc(int val, t_res *res)
{
	t_stack	*temp;
	int		i;
	int		diff;
	int		min_diff;
	int		target;

	temp = res->stack_b;
	i = 0;
	min_diff = INT_MAX;
	while (temp)
	{
		diff = val - temp->val;
		if (diff < min_diff && diff > 0)
		{
			min_diff = diff;
			target = i;
			ft_printf("min_diff %d, target %d\n", min_diff, target);
		}
		temp = temp->next;
		i++;
	}
	return (target);
}

void prepare_stack(t_res *res)
{
	t_stack	*temp;

	index_stack(res->stack_a, res->count_a);
	index_stack(res->stack_b, res->count_b);
	temp = res->stack_a;
	while (temp)
	{
		ft_printf("index %d\n", temp->index);
		temp->target = get_target_index_desc(temp->val, res);
		temp = temp->next;
	}
	print_list_vals(res);
	return ;
}

