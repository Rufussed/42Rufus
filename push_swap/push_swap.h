/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/06/28 13:24:44 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"

# define STACK_A 1
# define STACK_B 2

# define PRINT 1

typedef struct s_stack {
	int				value;
	int				index;
	int				cost;
	struct s_stack	*target;
//	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// resources to passed and free'd
typedef struct s_res {
	char			**input_array;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				count_a;
	int				count_b;
	int				print;
}	t_res;



int			check_atoi(const char *str, t_res *res);
void		stack_add_back(t_stack **lst, t_stack *new);
void		stack_add_front(t_stack **node, t_stack *new);
t_stack		*stack_new(int value);
t_stack		*stack_last(t_stack *node);
int			fill_stack_a(t_res *res);
void		exit_error(char *message, t_res *res);
int			stack_is_sorted(t_stack *node);
void		modified_lstclear(t_stack **lst);
void		free_input_array(char **array);
void		free_res(t_res *res);
void		sa(t_res *res);
void		print_list_values(t_res *res);
void		sa(t_res *res);
void		sb(t_res *res);
void		ss(t_res *res);
void		pa(t_res *res);
void		pb(t_res *res);
void		ra(t_res *res);
void		rb(t_res *res);
void		rr(t_res *res);
void		rra(t_res *res);
void		rrb(t_res *res);
void		rrr(t_res *res);
int			sort_stack(t_res *res);

#endif