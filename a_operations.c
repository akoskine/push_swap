/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:48 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:36 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute SA */
void	exec_sa(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (print == 1)
		write(1, "sa\n", 3);
}

/* Execute PA */
void	exec_pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (print == 1)
		write(1, "pa\n", 3);
}

/* Execute RA */
void	exec_ra(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

/* Execute RRA */
void	exec_rra(t_stack **stack_a, int print)
{
	t_stack	*tmp;
	t_stack	*tmp_second_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	tmp_second_last = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp_second_last->next->next)
		tmp_second_last = tmp_second_last->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	tmp_second_last->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}
