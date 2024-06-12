/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:57:29 by rlane             #+#    #+#             */
/*   Updated: 2024/06/12 15:52:06 by rlane            ###   ########.fr       */
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

void	free_path_data(t_path_data *path_data)
{
	if (path_data->queued_nodes)
		ft_lstclear(&path_data->queued_nodes, free);
	if (path_data->visited_nodes)
		ft_lstclear(&path_data->visited_nodes, free);
	if (path_data->current_node)
		free(path_data->current_node);
	if (path_data)
		free(path_data);
}

int	check_all_player_accessible_nodes(t_data *data)
{
	t_path_data	*path_data;
	int			result;

	path_data = malloc(sizeof(t_path_data));
	if (!path_data)
		return (0);
	path_data->current_node = malloc(sizeof(t_node));
	path_data->cnv = malloc(sizeof(t_node));
	if (!path_data->current_node || !path_data->cnv)
	{
		free(path_data);
		return (0);
	}
	path_data->visited_nodes = NULL;
	ft_printf("created path_data & current_node\n\n");//debug
	path_data->current_node->x = data->player_x;
	path_data->current_node->y = data->player_y;
	path_data->cnv->x = data->player_x;
	path_data->cnv->y = data->player_y;
	ft_printf("Player x = %d\n", data->player_x);//debug
	ft_printf("Player y = %d\n", data->player_y);//debug
	path_data->visited_nodes = ft_lstnew(path_data->cnv);
	path_data->queued_nodes = ft_lstnew(path_data->current_node);
	ft_printf("\ninitiallised queue_node\n\n");//debug
	while (path_data->queued_nodes)
	{
		path_data->current_node = (t_node *)path_data->queued_nodes->content;
		lst_remove_front(&path_data->queued_nodes);
		find_adjacent_nodes(data, path_data);
		path_data->cnv = malloc(sizeof(t_node));
		path_data->cnv->x = path_data->current_node->x;
		path_data->cnv->y = path_data->current_node->y;
		ft_printf("visited: %d, %d\n", path_data->cnv->x, path_data->cnv->y);//debug
		ft_lstadd_back(&path_data->visited_nodes, 
			ft_lstnew(path_data->cnv));
	}
	ft_printf("\nfinished finding adjacent nodes\n\n");//debug
	result = check_visited_for_keys_exit(data, path_data);
	free(path_data->cnv);
	free_path_data(path_data);
	return (result);
}

int	check_visited_for_keys_exit(t_data *data, t_path_data *path_data)
{
	t_list	*this_node;
	int		keys_found;
	int		exit_found;

	keys_found = 0;
	exit_found = 0;

	ft_printf("key_count = %d\n", data->key_count);//debug
	this_node = path_data->visited_nodes;
	while (this_node)
	{
		if (data->map[((t_node *)this_node->content)->y]
			[((t_node *)this_node->content)->x] == 'E')
			exit_found = 1;
		if (data->map[((t_node *)this_node->content)->y]
			[((t_node *)this_node->content)->x] == 'C')
			keys_found++;
		this_node = this_node->next;
	}
	ft_printf("keys accessible = %d\n", keys_found);//debug
	if (exit_found)
		ft_printf("exit accessible\n");//debug
	if (data->key_count == keys_found && exit_found)
		return (1);
	error_set(NO_VALID_PATH_ERROR);
	return (0);
}


void	find_adjacent_nodes(t_data *data, t_path_data *path_data)
{
	int		i;
	int		x;
	int		y;

	i = 1;
	while (i <= 4)
	{
		x = path_data->current_node->x;
		y = path_data->current_node->y;
		if (i == UP)
			y--;
		if (i == RIGHT)
			x++;
		if (i == DOWN)
			y++;
		if (i == LEFT)
			x--;
		check_and_queue_node(x, y, data, path_data);
		i++;
	}
}

void	check_and_queue_node(int x, int y, t_data *data, t_path_data *path_data)
{
	t_node	*adjacent_node;

	if (data->map[y][x] != '1')
	{
		adjacent_node = malloc(sizeof(t_node));
		if (!adjacent_node)
			return ;
		adjacent_node->x = x;
		adjacent_node->y = y;
		if (!(ft_lstfind(path_data->visited_nodes, adjacent_node) ||
				ft_lstfind(path_data->queued_nodes, adjacent_node)))
		{
			ft_lstadd_back(&path_data->queued_nodes, ft_lstnew(adjacent_node));
		}
		else
			free(adjacent_node);
	}
}
