/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/07/02 18:54:29 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/src/libft.h"

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

# define RESET "\033[0m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define BOLD_GREEN "\033[1;32m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define BROWN "\033[0;33m"
# define ORANGE "\033[0;33m"

# define RESET_CURSOR "\033[1G"
# define DELETE_LINE "\033[2K"

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
void		init_res(t_res *res);
int			get_instructions(t_res *res);

#endif