/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:37 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:38 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute SB */
void	exec_sb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (print == 1)
		write(1, "sb\n", 3);
}

/* Execute PB */
void	exec_pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (print == 1)
		write(1, "pb\n", 3);
}

/* Execute RB */
void	exec_rb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

/* Execute RRB */
void	exec_rrb(t_stack **stack_b, int print)
{
	t_stack	*tmp;
	t_stack	*tmp_second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	tmp_second_last = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp_second_last->next->next)
		tmp_second_last = tmp_second_last->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	tmp_second_last->next = NULL;
	if (print == 1)
		write(1, "rrb\n", 4);
}
