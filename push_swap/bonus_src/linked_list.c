/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:20:05 by rlane             #+#    #+#             */
/*   Updated: 2024/07/01 17:32:05 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the last node of the list.

t_stack	*stack_last(t_stack *node)
{
	t_stack	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp -> next != NULL)
		temp = temp -> next;
	return (temp);
}

void	stack_add_back(t_stack **node, t_stack *new)
{
	t_stack	*temp;

	if (!node || !new)
		return ;
	if (*node == NULL)
		*node = new;
	else
	{
		temp = stack_last(*node);
		temp -> next = new;
	}
}

void	stack_add_front(t_stack **node, t_stack *new)
{
	if (!node || !new)
		return ;
	new -> next = *node;
	*node = new;
}
// since we are using int pointers we dont need to free content

void	modified_lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
