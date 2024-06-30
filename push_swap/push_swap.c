/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:49:39 by rlane             #+#    #+#             */
/*   Updated: 2024/06/30 17:08:15 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_a(t_res *res)
{
	int		val;
	int		i;

	i = 0;
	while (res->input_array[i])
	{
		val = check_atoi(res->input_array[i], res);
		stack_add_back(&res->stack_a, stack_new(val));
		i++;
	}
	res->count_a = i;
	res->count_b = 0;
	return (1);
}

char	**get_input_data(int argc, char **argv)
{
	char	**input_array;
	int		i;

	if (argc == 2)
		input_array = ft_split(argv[1], ' ');
	else
	{
		input_array = (char **)malloc(sizeof(char *) * argc);
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
		input_array[i] = NULL;
	}
	return (input_array);
}

void	init_res(t_res *res)
{
	res->input_array = NULL;
	res->stack_a = NULL;
	res->stack_b = NULL;
	res->print = PRINT;
}

int	main(int argc, char **argv)
{
	t_res	*res;

	res = (t_res *)malloc(sizeof(t_res));
	init_res(res);

	if (argc == 1)
	{
		ft_putstr("\n\033[31mUsage: ./push_swap [numbers]\033[0m\n\n");
		free_res(res);
		return (0);
	}
	res->input_array = get_input_data(argc, argv);
	if (!res->input_array)
	{
		ft_printf("\n\033[31mError: memory allocation failed ! \033[0m\n\n");
		free(res);
		return (0);
	}
	fill_stack_a(res);
	return (sort_stack(res));
}
