/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:57:29 by rlane             #+#    #+#             */
/*   Updated: 2024/06/11 14:27:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_node
{
	int	x;
	int	y;
}	t_node;

void	*lst_remove_front(t_list **lst)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

int	check_all_player_accessible_nodes(t_data *data)
{
	t_list	*queued_nodes;
	t_list	*visited_nodes;
	t_node	*current_node;
	int		i;
	int		keys_found;

	current_node = malloc(sizeof(t_node));
	if (!current_node)
		return (0);
	keys_found = 0;
	current_node->x = data->player_x;
	current_node->y = data->player_y;
	queued_nodes = ft_lstnew(current_node);
	while (queued_nodes)
	{
		current_node = queued_nodes->content;
		if (data->map[current_node->y][current_node->x] == 'C')
			keys_found++;
		visited_nodes = ft_lstnew(current_node);
		queued_nodes = lst_remove_front(queued_nodes);
		find_adjacent_nodes(data, current_node, queued_nodes, visited_nodes);
		//need code to check if exit is reachable and collectables are matching
	}
}

void	find_adjacent_nodes(t_data *data, t_node *current_node, 
	t_list **queued_nodes, t_list **visited_nodes)
{
	t_node	*adjacent_node;
	int		i;
	int		x;
	int		y;

	i = 1;
	while (i <= 4)
	{
		if (i == UP)
			y--;
		if (i == RIGHT)
			x++;
		if (i == DOWN)
			y++;
		if (i == LEFT)
			x--;
		if (data->map[y][x] != 1)
		{
			adjacent_node = malloc(sizeof(t_node));
			if (!adjacent_node)
				return (0);
			adjacent_node->x = x;
			adjacent_node->y = y;
			if (!ft_lstfind(visited_nodes, adjacent_node))
				queued_nodes = ft_lstnew(adjacent_node);
		}
		lst_remove_front(queued_nodes);
		x = current_node->x;
		y = current_node->y;
		i++;
	}
}

