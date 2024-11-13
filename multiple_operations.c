/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:32 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:04 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute SS */

void	exec_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	exec_sa(stack_a, 0);
	exec_sb(stack_b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}

/* Execute RR */

void	exec_rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	exec_ra(stack_a, 0);
	exec_rb(stack_b, 0);
	if (print == 1)
		write(1, "rr\n", 3);
}

/* Execute RRR */

void	exec_rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	exec_rra(stack_a, 0);
	exec_rrb(stack_b, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
}
