/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:49:39 by rlane             #+#    #+#             */
/*   Updated: 2024/07/09 12:48:57 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

		if (argv[1][0] == '\0')
			exit_error(res);

	res->input_array = get_input_data(argc, argv);
	if (!res->input_array)
		exit_error(res);
	fill_stack_a(res);
	get_instructions(res);
	if (stack_is_sorted(res->stack_a) && res->count_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_res(res);
	return (1);
}
