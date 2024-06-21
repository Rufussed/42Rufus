/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder_list_init_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:15:41 by rlane             #+#    #+#             */
/*   Updated: 2024/06/12 20:17:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lst_remove_front(t_list **lst)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

int	ft_lstfind(t_list *lst, t_node *node)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (((t_node *)temp->content)->x == node->x
			&& ((t_node *)temp->content)->y == node->y)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_path_data	*initialise_path_data(t_path_data *path_data)
{
	path_data = malloc(sizeof(t_path_data));
	path_data->current_node = malloc(sizeof(t_node));
	path_data->temp_node = malloc(sizeof(t_node));
	path_data->visited_nodes = NULL;
	path_data->queued_nodes = NULL;
	return (path_data);
}

void	free_path_data(t_path_data *path_data)
{
	if (path_data->queued_nodes)
		ft_lstclear(&path_data->queued_nodes, free);
	if (path_data->visited_nodes)
		ft_lstclear(&path_data->visited_nodes, free);
	if (path_data)
		free(path_data);
}
