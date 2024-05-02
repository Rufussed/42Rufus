/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:01:58 by rlane             #+#    #+#             */
/*   Updated: 2024/05/02 18:47:48 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "ft_lstnew.c"
// #include "ft_lstadd_front.c"
// #include "ft_lstsize.c"
// #include "ft_lstlast.c"
// #include "ft_lstadd_back.c"
// #include "ft_lstdelone.c"

// Deletes and frees the given node and every successor of that node, using the
// function ’del’ and free(3).
// Finally, the pointer to the list must be set to NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;	

	while (*lst)
	{
		temp = (*lst)-> next ;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
/*
void del(void *content) 
{
    free(content);
}

int	main(void)
{
	int	content1 = 1;
	int	content2 = 2;
	int	content3 = 3;
	int	content4 = 0;
	int	node_count = 0;

	t_list	*test_list;
	t_list	*altered_list;
	t_list	*temp_list;
	t_list	*temp_list2;

	test_list = NULL;

	test_list = ft_lstnew(&content1);
	ft_lstadd_back(&test_list, ft_lstnew(&content2));
	ft_lstadd_back(&test_list, ft_lstnew(&content3));
	ft_lstadd_front(&test_list, ft_lstnew(&content4));

	temp_list = test_list;

	printf("\n\nTest List\n\n");
	while (temp_list)
	{
		printf("node %d - adr %p - content %d - next adr %p\n\n", node_count, temp_list, *(int *)(temp_list->content), temp_list -> next);
		temp_list = temp_list->next;
		node_count++;
	}

	temp_list = test_list;
	temp_list2 = ft_lstlast(temp_list);

	ft_lstclear(&temp_list2, &del);

	node_count = 0;
	printf("\n\nAltered List\n\n");
	while (temp_list)
	{
		printf("node %d - adr %p - content %d - next adr %p\n\n", node_count, temp_list, *(int *)(temp_list->content), temp_list -> next);
		temp_list = temp_list->next;
		node_count++;
	}

	return (0);
}*/