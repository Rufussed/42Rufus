/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:48:25 by rlane             #+#    #+#             */
/*   Updated: 2024/05/01 14:43:34 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "ft_lstnew.c"

// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.
// 1. set new element next adress to point to the start of the existing list
// set the existing list pointer to point to the new element

void ft_lstadd_front(t_list **lst, t_list *new)
{
    new -> next = *lst;
    *lst = new;
}
#include <string.h>  // Include for strcmp
int	main(void)
{
	t_list	*list = NULL; // Initialize to NULL for the empty list scenario.
	t_list	*new;
	char	*str1 = "Hello";
	char	*str2 = "World";

	// Creating first list node
	list = ft_lstnew(str1);
	if (list == NULL)
		return (1); // Handling potential allocation failures

	// Creating new node to be added at the front
	new = ft_lstnew(str2);
	if (new == NULL)
	{
		free(list); // Clean up previously allocated memory
		return (1);
	}

	// Initial list content
	printf("\nInitial content: %s\n", (char *) list->content);

	// Adding new node to the front of the list
	ft_lstadd_front(&list, new);

	// Content after adding new at the front
	printf("\nNew front content: %s\n", (char *) list->content);

	// Freeing nodes
	free(list->next); // Free the original first node
	free(list);       // Free the new front node

	return (0);
}