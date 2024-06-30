/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:20:05 by rlane             #+#    #+#             */
/*   Updated: 2024/06/30 17:18:44 by rlane            ###   ########.fr       */
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

t_stack	*stack_new(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->next = NULL;
	node->target = 0;
	node->push_cost = 0;
	node->full_cost = 0;
	node->index = 0;
	node->max = FALSE;
	node->min = FALSE;
	node->median = ABOVE;
	return (node);
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


