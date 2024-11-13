/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:48 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:02 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_set_ra_rb(t_stack **stack_a, t_stack **stack_b, int index)
{
	while ((*stack_a)->index != index && find_b_spot(*stack_b, index) > 0)
		exec_rr(stack_a, stack_b, 1);
	while ((*stack_a)->index != index)
		exec_ra(stack_a, 1);
	while (find_b_spot(*stack_b, index) > 0)
		exec_rb(stack_b, 1);
	exec_pb(stack_a, stack_b, 1);
	return (-1);
}

int	move_set_rra_rrb(t_stack **stack_a, t_stack **stack_b, int index)
{
	while ((*stack_a)->index != index && find_b_spot(*stack_b, index) > 0)
		exec_rrr(stack_a, stack_b, 1);
	while ((*stack_a)->index != index)
		exec_rra(stack_a, 1);
	while (find_b_spot(*stack_b, index) > 0)
		exec_rrb(stack_b, 1);
	exec_pb(stack_a, stack_b, 1);
	return (-1);
}

int	move_set_ra_rrb(t_stack **stack_a, t_stack **stack_b, int index)
{
	while ((*stack_a)->index != index)
		exec_ra(stack_a, 1);
	while (find_b_spot(*stack_b, index) > 0)
		exec_rrb(stack_b, 1);
	exec_pb(stack_a, stack_b, 1);
	return (-1);
}

int	move_set_rra_rb(t_stack **stack_a, t_stack **stack_b, int index)
{
	while ((*stack_a)->index != index)
		exec_rra(stack_a, 1);
	while (find_b_spot(*stack_b, index) > 0)
		exec_rb(stack_b, 1);
	exec_pb(stack_a, stack_b, 1);
	return (-1);
}
