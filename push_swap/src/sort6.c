/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:21:25 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 12:20:12 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_smallest_to_top(t_res *res)
{
	int		i;
	t_stack	*min;

	index_stack(res->stack_a, res->count_a);
	set_max_min_index(res);
	i = res->min_index_a;
	min = get_stack_index(res->stack_a, i);
	if (min->median == ABOVE)
	{
		while (i > 0)
		{
			ra(res);
			i--;
		}
	}
	if (min->median == BELOW)
	{
		i = res->count_a - i;
		while (i > 0)
		{
			rra(res);
			i--;
		}
	}
}
