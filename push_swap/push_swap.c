/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:49:39 by rlane             #+#    #+#             */
/*   Updated: 2024/06/27 13:38:26 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_values(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		ft_printf("node: %d  ", i);
		ft_printf("value: %d\n", (int)(intptr_t)temp->content);
		temp = temp->next;
		i++;
	}
}

void	free_input_array(char **array)
{
	int	i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// since we are using int pointers we dont need to free content
void	modified_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	fill_stack_a(char **input_array, t_list **stack_a)
{
	int		value;
	int		i;

	i = 0;
	while (input_array[i])
	{
		if (!check_atoi(input_array[i], &value))
			return (0);
		ft_lstadd_back(stack_a, ft_lstnew((void *)(intptr_t)value));
		i++;
	}
	return (1);
}

char	**get_input_data(int argc, char **argv)
{
	char	**input_array;
	int		i;

	input_array = (char **)malloc(sizeof(char *) * argc);
	if (argc == 2)
	{
		input_array = ft_split(argv[1], ' ');
		if (!input_array)
				return (NULL);
	}
	else
	{
		i = 0;
		while (i < argc - 1)
		{
			input_array[i] = ft_strdup(argv[i + 1]);
			if (!input_array[i])
			{
				free_input_array(input_array);
				return (NULL);
			}
			i++;
		}
	}
	return (input_array);
}

int	main(int argc, char **argv)
{
	char	**input_array;
	t_list	*stack_a;

	if (argc == 1)
	{
		ft_putstr("Usage: ./push_swap [numbers]\n");
		return (0);
	}
	input_array = get_input_data(argc, argv);
	if (!input_array)
	{
		ft_printf("Error: memory allocation failed\n");
		return (0);
	}
	stack_a = NULL;
	if (!fill_stack_a(input_array, &stack_a))
	{
		ft_putstr("Error: input numbers only!\n");
		free_input_array(input_array);
		return (0);
	}
	print_list_values(stack_a);
	free_input_array(input_array);
	modified_lstclear(&stack_a);
	return (0);
}


