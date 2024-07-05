/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:00 by rlane             #+#    #+#             */
/*   Updated: 2024/07/05 16:30:57 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*print_node_details_return_next(t_stack *node)
{
	if (node)
	{
		ft_printf(PURPLE "%d\t%d\t%d\t%d", node->val, 
			node->push_cost, node->full_cost, node->target);
		node = node->next;
	}
	return (node);
}

void	print_list_vals(t_res *res, char *message)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = res->stack_a;
	temp_b = res->stack_b;
	if (res->print == PRINT)
	{
		ft_printf(YELLOW "%s\n" RESET, message);
		ft_printf("val\tp_cost\tf_cost\tt_ind\tval\tp_cost\tf_cost\tt_ind\n");
		while (temp_a || temp_b)
		{
			if (temp_a)
				temp_a = print_node_details_return_next(temp_a);
			else
				ft_printf("\t\t\t");
			if (temp_b)
			{
				ft_printf(GREEN "\t%d\t%d\t%d\t%d\n" RESET, temp_b->val, 
					temp_b->push_cost, temp_b->full_cost, temp_b->target);
				temp_b = temp_b->next;
			}
			else
				ft_printf("\n" RESET);
		}
	}
}
