/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:49:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/09 13:02:50 by rlane            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_res	*res;

	if (argc == 1)
		return (0);
	res = (t_res *)malloc(sizeof(t_res));
	init_res(res);
//	if (argc == 2) 
	//{
	//	check_atoi(argv[1], res);
		if (argv[1][0] == '\0')
			exit_error(res);
//		free_res(res);
//return (0);
//	}
	res->input_array = get_input_data(argc, argv);
	if (!res->input_array)
		exit_error(res);
	fill_stack_a(res);
	return (sort_stack(res));
}
