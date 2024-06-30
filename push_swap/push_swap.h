/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/06/30 17:06:05 by rlane            ###   ########.fr       */
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

# define ABOVE 1
# define BELOW 2

typedef struct s_stack {
	int				val;
	int				index;
	int				push_cost;
	int				full_cost;
	int				max;
	int				min;
	int				median;
	int 			target;
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
t_stack		*stack_new(int val);
t_stack		*stack_last(t_stack *node);
int			fill_stack_a(t_res *res);
void		exit_error(char *message, t_res *res);
int			stack_is_sorted(t_stack *node);
void		modified_lstclear(t_stack **lst);
void		free_input_array(char **array);
void		free_res(t_res *res);
void		sa(t_res *res);
void		print_list_vals(t_res *res);
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
void		prepare_stack(t_res *res);
void		index_stack(t_stack *stack, int count);


#endif