/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:19 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* check_input */

int			check_nbr(char *arg, int *zero);
int			check_duplicates(char **arg, int start);
int			quoted_arg(char **argv);
int			check_input(int argc, char **argv);

/* fill_values_indexes */

t_stack		*fill_new(int value);
void		fill_values(t_stack **stack, t_stack *new);
void		fill_index(t_stack *stack, int stack_len);
t_stack		*quoted_str(char **argv);
t_stack		*fill_values_indexes(int argc, char **argv);

/* utils */

void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			get_stack_len(t_stack *stack);
int			stack_sorted(t_stack *stack);
long int	ft_atoi_long(const char *str);

/* sort */

void		sort_only_three(t_stack **stack);
void		exec_sort_a_moves(t_stack **stack_a, int cost);
void		sort_b(t_stack **stack_a, t_stack **stack_b);
void		sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a);

/* a_operations */

void		exec_sa(t_stack **stack_a, int print);
void		exec_pa(t_stack **stack_a, t_stack **stack_b, int print);
void		exec_ra(t_stack **stack_a, int print);
void		exec_rra(t_stack **stack_a, int print);

/* b_operations */

void		exec_sb(t_stack **stack_b, int print);
void		exec_pb(t_stack **stack_a, t_stack **stack_b, int print);
void		exec_rb(t_stack **stack_b, int print);
void		exec_rrb(t_stack **stack_b, int print);

/* multiple_operations */

void		exec_ss(t_stack **stack_a, t_stack **stack_b, int print);
void		exec_rr(t_stack **stack_a, t_stack **stack_b, int print);
void		exec_rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* sort_utils */

int			find_max_index(t_stack *stack);
int			find_min_index(t_stack *stack);
int			find_specific_index(t_stack *stack, int index);
int			find_last_index(t_stack *stack);
int			find_b_spot(t_stack *stack_b, int index);

/* cost_utils */

int			cheapest_move(t_stack *a, t_stack *b);
int			cost_ra_rb(t_stack *a, t_stack *b, int index);
int			cost_rra_rrb(t_stack *a, t_stack *b, int index);
int			cost_ra_rrb(t_stack *a, t_stack *b, int index);
int			cost_rra_rb(t_stack *a, t_stack *b, int index);

/* move_sets */

int			move_set_ra_rb(t_stack **a, t_stack **b, int index);
int			move_set_rra_rrb(t_stack **a, t_stack **b, int index);
int			move_set_ra_rrb(t_stack **a, t_stack **b, int index);
int			move_set_rra_rb(t_stack **a, t_stack **b, int index);

/* checker */

char		*check_stack(t_stack **stack_a, t_stack **stack_b, char *str);
void		checker_exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
