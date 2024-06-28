/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:36:18 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 14:15:54 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_res *res)
{
	t_stack	*stack;

	stack = res->stack_a;
	if (stack->value > stack->next->value 
		&& stack->value < stack->next->next->value)
		sa(res);
	else if (stack->value > stack->next->value 
		&& stack->value > stack->next->next->value)
	{
		sa(res);
		rra(res);
	}
	else if (stack->value < stack->next->value 
		&& stack->value > stack->next->next->value)
		ra(res);
	else if (stack->value < stack->next->value
		&& stack->value < stack->next->next->value)
		rra(res);
}

void index_stack(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	algo_sort(t_res *res)
{
	while (res->count_a > 3)
	{
		
		if (res->count_b < 3)
			pb(res);
		else
		{
			//sort a to b in descending order
		}
	}
	sort_three_a(res);
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
		if (res->stack_a->value > res->stack_a->next->value)
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
