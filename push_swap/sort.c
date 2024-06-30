/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:36:18 by rlane             #+#    #+#             */
/*   Updated: 2024/06/30 17:16:59 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_highest_node(t_stack *stack)
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
	t_stack *highest;

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
	while (res->count_a > 5)
	{
		//if (res->count_b < 2)
			pb(res);
		//else
		//{
			//sort a to b in descending order
		//}
	}
	ft_printf("Here?\n");
		prepare_stack(res);
		//sort_three_a(res);
	//sort b to a in ascending order
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
	free_res(res);
	return (1);
}
