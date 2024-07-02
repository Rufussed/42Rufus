/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:36:18 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 12:28:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_highest_node(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*highest;

	temp = stack;
	highest = temp;
	while (temp)
	{
		if (temp->val > highest->val)
			highest = temp;
		temp = temp->next;
	}
	return (highest);
}

void	sort_three_a(t_res *res)
{
	t_stack	*highest;

	highest = get_highest_node(res->stack_a);
	if (res->stack_a->val == highest->val)
		ra(res);
	if (res->stack_a->next->val == highest->val)
		rra(res);
	if (res->stack_a->val > res->stack_a->next->val)
		sa(res);
}

void	algo_sort(t_res *res)
{
	while (res->count_a > 3)
	{
		if (res->count_b < 2)
			pb(res);
		else
		{
			prepare_stack_a(res);
			if (res->count_b == 5)
				print_list_vals(res, "after prepare stack a and count_b = 5");
			pb_descending(res);
		}
	}
	sort_three_a(res);
	while (res->count_b > 0)
	{
		prepare_stack_b(res);
		if (res->count_a == 5)
			print_list_vals(res, "after prepare stack b and count_a = 5");
		pa_ascending(res);
	}
	rotate_smallest_to_top(res);
}

int	sort_stack(t_res *res)
{
	if (res->count_a == 1)
		return (1);
	if (stack_is_sorted(res->stack_a))
	{
		free_res(res);
		return (1);
	}
	if (res->count_a == 2)
	{
		if (res->stack_a->val > res->stack_a->next->val)
			sa(res);
		free_res(res);
		return (1);
	}
	if (res->count_a == 3)
	{
		sort_three_a(res);
		free_res(res);
		return (1);
	}
	algo_sort(res);
	print_list_vals(res, "sorted array");
	free_res(res);
	return (1);
}
