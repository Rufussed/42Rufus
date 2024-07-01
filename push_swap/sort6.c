/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:21:25 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 19:49:53 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest(t_res *res, int i, int median)
{
	if (median == ABOVE)
	{
		while (i > 0)
		{
			ra(res);
			i--;
		}
	}
	if (median == BELOW)
	{
		i = res->count_a - i;
		while (i > 0)
		{
			rra(res);
			i--;
		}
	}
}

void	rotate_smallest_to_top(t_res *res)
{
	int		i;
	t_stack	*temp;
	t_stack	*min;

	index_stack(res->stack_a, res->count_a);
	set_max_min_index(res);
	print_list_vals(res);

	temp = res->stack_a;
	min = NULL;
	while (temp)
	{
		if (temp->index == res->min_index_a)
		{
			min = temp;
			break ;
		}
		temp = temp->next;
	}
	i = min->index;
	rotate_smallest(res, i, min->median);
}
