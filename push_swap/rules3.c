/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:56:33 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 11:59:33 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("rra\n");
	print_list_values(res);
}

void	rrb(t_res *res)
{
	reverse_rotate(&res->stack_b);
	ft_printf("rrb\n");
	print_list_values(res);
}

void	rrr(t_res *res)
{
	reverse_rotate(&res->stack_a);
	reverse_rotate(&res->stack_b);
	ft_printf("rrr\n");
	print_list_values(res);
}

