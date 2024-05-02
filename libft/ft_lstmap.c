/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:50:20 by rlane             #+#    #+#             */
/*   Updated: 2024/05/02 15:18:22 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include "ft_lstnew.c"
#include "ft_lstadd_front.c"
#include "ft_lstsize.c"
#include "ft_lstlast.c"
#include "ft_lstadd_back.c"
#include "ft_lstdelone.c"
#include "ft_lstclear.c"
#include "ft_lstiter.c"
*/

// Iterates the list ’lst’ and applies the function ’f’ on the content of each
// node. Creates a newlist resulting of the successive applications of the 
// function ’f’. The ’del’ function is used todelete the content of a node 
// if needed.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	temp = lst;
	while (temp)
	{
		new_node = ft_lstnew(f(temp -> content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		temp = temp -> next;
	}
	return (new_list);
}
/*
void del(void *content) {
    free(content);
}

void *f(void *content) {
    int *result = malloc(sizeof(int));
    if (result == NULL) 
        return NULL;
    *result = 2 * *(int *)content;  // Dereference, multiply, and store
    return result;  // Return the pointer to the new data
}

#include <string.h>
int	main(void)
{
	int	content1 = 1;
	int	content2 = 2;
	int	content3 = 3;
	int	content4 = 0;
	int	node_count = 0;

	t_list	*test_list;
	t_list	*mapped_list;
	t_list	*temp_list;

	test_list = NULL;

	test_list = ft_lstnew(&content1);
	ft_lstadd_back(&test_list, ft_lstnew(&content2));
	ft_lstadd_back(&test_list, ft_lstnew(&content3));
	ft_lstadd_front(&test_list, ft_lstnew(&content4));

	temp_list = test_list;


	printf("\n\nTest List\n\n");
	while (temp_list)
	{
		printf("content of node %d: %d\n", node_count, 
			*(int *)(temp_list->content));
		temp_list = temp_list->next;
		node_count++;
	}

	mapped_list = ft_lstmap(test_list, &f, &del);

	temp_list = mapped_list;
	node_count = 0;
	printf("\n\nMapped List (* 2)\n\n");
	while (temp_list)
	{
		printf("content of node %d: %d\n", node_count, 
			*(int *)(temp_list->content));
		temp_list = temp_list->next;
		node_count++;
	}

	return (0);
}*/