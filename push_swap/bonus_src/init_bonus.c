/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:31:59 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 17:57:28 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*stack_new(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->next = NULL;
	node->target = NONE;
	node->push_cost = 0;
	node->full_cost = 0;
	node->index = 0;
	node->median = UNKNOWN;
	return (node);
}

void	init_res(t_res *res)
{
	res->input_array = NULL;
	res->stack_a = NULL;
	res->stack_b = NULL;
	res->count_a = 0;
	res->count_b = 0;
	res->print = NO_PRINT;
}
