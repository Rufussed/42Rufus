/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:19:37 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 11:17:56 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_res(t_res *res)
{
	if (res->input_array)
		free_input_array(res->input_array);
	if (res->stack_a)
		modified_lstclear(&res->stack_a);
	if (res->stack_b)
		modified_lstclear(&res->stack_b);
	if (res)
		free(res);
}

void	free_input_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_error(char *message, t_res *res)
{
	ft_printf("\n\033[31mError: %s !\033[0m\n\n", message);
	free_res(res);
	exit(1);
}
