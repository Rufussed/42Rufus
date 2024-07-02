/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:56:33 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 11:39:43 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_res *res)
{
	t_stack	*temp;

	if (!res->stack_a)
		return ;
	temp = res->stack_a;
	res->stack_a = res->stack_a->next;
	stack_add_front(&res->stack_b, temp);
	res->count_a--;
	res->count_b++;
	ft_printf("pb\n");
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_res *res)
{
	rotate(&res->stack_a);
	ft_printf("ra\n");
}

void	rb(t_res *res)
{
	rotate(&res->stack_b);
	ft_printf("rb\n");
}

void	rr(t_res *res)
{
	rotate(&res->stack_a);
	rotate(&res->stack_b);
	ft_printf("rr\n");
}
