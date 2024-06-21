/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufus <rufus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:57:29 by rlane             #+#    #+#             */
/*   Updated: 2024/06/15 14:28:13 by rufus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_all_player_accessible_nodes(t_data *data)
{
	t_path_data	*path_data;
	int			result;

	path_data = initialise_path_data(NULL);
	path_data->current_node->x = data->player_x;
	path_data->current_node->y = data->player_y;
	path_data->temp_node->x = data->player_x;
	path_data->temp_node->y = data->player_y;
	path_data->visited_nodes = ft_lstnew(path_data->temp_node);
	path_data->queued_nodes = ft_lstnew(path_data->current_node);
	while (path_data->queued_nodes)
	{
		path_data->current_node = (t_node *)path_data->queued_nodes->content;
		lst_remove_front(&path_data->queued_nodes);
		find_adjacent_nodes(data, path_data);
		ft_printf("pathfinder visited: %d, %d\n", path_data->current_node->x,
			path_data->current_node->y);
		ft_lstadd_back(&path_data->visited_nodes,
			ft_lstnew(path_data->current_node));
	}
	result = check_visited_for_keys_exit(data, path_data);
	free_path_data(path_data);
	return (result);
}

void	pathfinder_report(t_data *data, int keys_found, int exit_found)
{
	ft_printf("\npathfinder visited %d nodes\n", data->accessible_nodes);
	ft_printf("from a possible of %d nodes\n", data->floor_count + 1);
	ft_printf("\ntotal keys on map = %d\nkeys accessible = %d\n\n",
		data->key_count, keys_found);
	if (keys_found < data->key_count)
		ft_printf("not all keys are accessible\n\n");
	else
		ft_printf("all keys are accessible\n\n");
	if (exit_found)
		ft_printf("exit accessible\n\n");
	else
		ft_printf("exit not accessible\n\n");
}

int	check_visited_for_keys_exit(t_data *data, t_path_data *path_data)
{
	t_list	*this_node;
	int		keys_found;
	int		exit_found;

	keys_found = 0;
	exit_found = 0;
	this_node = path_data->visited_nodes;
	while (this_node)
	{
		data->accessible_nodes++;
		if (data->map[((t_node *)this_node->content)->y]
			[((t_node *)this_node->content)->x] == 'E')
			exit_found = 1;
		if (data->map[((t_node *)this_node->content)->y]
			[((t_node *)this_node->content)->x] == 'C')
			keys_found++;
		this_node = this_node->next;
	}
	pathfinder_report(data, keys_found, exit_found);
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
		adjacent_node->x = x;
		adjacent_node->y = y;
		if (!(ft_lstfind(path_data->visited_nodes, adjacent_node)
				|| ft_lstfind(path_data->queued_nodes, adjacent_node)))
		{
			ft_lstadd_back(&path_data->queued_nodes, ft_lstnew(adjacent_node));
		}
		else
			free(adjacent_node);
	}
}
