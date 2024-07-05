/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:47:26 by rlane             #+#    #+#             */
/*   Updated: 2024/07/05 16:40:07 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_instruction(t_res *res, char *instruction)
{
	if (!ft_strncmp(instruction, "rrb", 3))
		rrb(res);
	else if (!ft_strncmp(instruction, "rrr", 3))
		rrr(res);
	else if (!ft_strncmp(instruction, "rra", 3))
		rra(res);
	else if (!ft_strncmp(instruction, "sa", 2))
		sa(res);
	else if (!ft_strncmp(instruction, "sb", 2))
		sb(res);
	else if (!ft_strncmp(instruction, "ss", 2))
		ss(res);
	else if (!ft_strncmp(instruction, "pa", 2))
		pa(res);
	else if (!ft_strncmp(instruction, "pb", 2))
		pb(res);
	else if (!ft_strncmp(instruction, "ra", 2))
		ra(res);
	else if (!ft_strncmp(instruction, "rb", 2))
		rb(res);
	else if (!ft_strncmp(instruction, "rr", 2))
		rr(res);
	else
		return (0);
	return (1);
}

int	get_instructions(t_res *res)
{
	char	*instruction;

	print_list_vals(res, "stacks before instructions:");
	instruction = get_next_line(0);
	while (instruction)
	{
		if (!execute_instruction(res, instruction))
		{
			if (ft_strlen(instruction) > 0 && instruction[0] != '\n'
				&& instruction[0] != '\0')
				exit_error(res);
			print_list_vals(res, "stacks after instruction:");
			free(instruction);
			break ;
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	return (1);
}
