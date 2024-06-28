/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:56:33 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 11:58:37 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **node)
{
	t_stack	*temp;

	if (!node || !*node || !(*node)->next)
		return ;
	temp = *node;
	*node = (*node)->next;
	temp->next = (*node)->next;
	(*node)->next = temp;
}

void	sa(t_res *res)
{
	if (res->count_a < 2)
		return ;
	swap(&res->stack_a);
	ft_printf("sa\n");
	print_list_values(res);
}

void	sb(t_res *res)
{
	if (res->count_b < 2)
		return ;
	swap(&res->stack_b);
	ft_printf("sb\n");
	print_list_values(res);
}

void	ss(t_res *res)
{
	swap(&res->stack_a);
	swap(&res->stack_b);
	ft_printf("ss\n");
	print_list_values(res);
}

void	pa(t_res *res)
{
	t_stack	*temp;

	if (!res->stack_b)
		return ;
	temp = res->stack_b;
	res->stack_b = res->stack_b->next;
	stack_add_front(&res->stack_a, temp);
	res->count_a++;
	res->count_b--;
	ft_printf("pa\n");
	print_list_values(res);
}
