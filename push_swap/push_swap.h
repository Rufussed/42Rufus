/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 12:14:36 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"

# define STACK_A 1
# define STACK_B 2

# define PRINT 1
# define NO_PRINT 0

# define TRUE 1
# define FALSE 0

# define UNKNOWN 0
# define ABOVE 1
# define BELOW 2

# define NONE -1

typedef struct s_stack {
	int				val;
	int				index;
	int				push_cost;
	int				full_cost;
	int				median;
	int				target;
	struct s_stack	*next;
}	t_stack;

// resources to passed and free'd
typedef struct s_res {
	char			**input_array;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				count_a;
	int				max_index_b;
	int				min_index_a;
	int				count_b;
	int				print;
}	t_res;

int			check_atoi(const char *str, t_res *res);
void		stack_add_back(t_stack **lst, t_stack *new);
void		stack_add_front(t_stack **node, t_stack *new);
t_stack		*stack_new(int val);
t_stack		*stack_last(t_stack *node);
int			fill_stack_a(t_res *res);
void		exit_error(char *message, t_res *res);
int			stack_is_sorted(t_stack *node);
void		modified_lstclear(t_stack **lst);
void		free_input_array(char **array);
void		free_res(t_res *res);
void		sa(t_res *res);
void		print_list_vals(t_res *res, char *message);
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
void		prepare_stack_a(t_res *res);
void		index_stack(t_stack *stack, int count);
void		init_res(t_res *res);
void		pb_descending(t_res	*res);
t_stack		*get_stack_index(t_stack *stack, int i);
void		set_max_min_index(t_res *res);
int			get_target_index_desc(int val, t_res *res);
void		prepare_stack_b(t_res *res);
void		pa_ascending(t_res *res);
int			ft_abs(int n);
int			find_cheapest_push(t_stack *stack);
int			find_cheapest_push(t_stack *stack);
void		rotate_stack_a(t_res *res, int temp_median, int p_cost_a);
void		rotate_stack_b(t_res *res, int target_median, int p_cost_b);
void		rotat_stacks_synched(t_res *res, t_stack *temp, t_stack *target);
void		rotate_smallest_to_top(t_res *res);
#endif