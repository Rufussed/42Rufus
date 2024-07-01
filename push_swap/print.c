/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:00 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 18:51:45 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_vals(t_res *res)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = res->stack_a;
	temp_b = res->stack_b;
	if (res->print == PRINT)
	{
		ft_printf("val\tp_cost\tf_cost\tt_ind\tval\tp_cost\tf_cost\tt_ind\n");
		while (temp_a || temp_b)
		{
			if (temp_a)
			{
				ft_printf("\033[32m%d\t%d\t%d\t%d", temp_a->val, 
				temp_a->push_cost, temp_a->full_cost, temp_a->target);
				temp_a = temp_a->next;
			}
			else
				ft_printf("\t\t\t");
			if (temp_b)
			{
				ft_printf("\033[35m\t%d\t%d\t%d\t%d\033[0m\n", temp_b->val, 
				temp_b->push_cost, temp_b->full_cost, temp_b->target);
				temp_b = temp_b->next;
			}
			else
				ft_printf("\n\033[0m");
		}
	}
}
