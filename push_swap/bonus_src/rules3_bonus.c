/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:39:24 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 16:20:30 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	temp = *stack;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_res *res)
{
	reverse_rotate(&res->stack_a);
}

void	rrb(t_res *res)
{
	reverse_rotate(&res->stack_b);
}

void	rrr(t_res *res)
{
	reverse_rotate(&res->stack_a);
	reverse_rotate(&res->stack_b);
}
