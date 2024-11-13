/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:28 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:11 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only_three(t_stack **stack)
{
	int		max_index;

	max_index = find_max_index(*stack);
	if ((*stack)->index == max_index)
		exec_ra(stack, 1);
	else if ((*stack)->next->index == max_index)
		exec_rra(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		exec_sa(stack, 1);
}

void	exec_sort_a_moves(t_stack **stack_a, int cost)
{	
	if (cost <= get_stack_len (*stack_a) / 2)
	{
		while (cost != 0)
		{
			exec_ra(stack_a, 1);
			cost--;
		}
	}
	else
	{
		cost = get_stack_len(*stack_a) - cost;
		while (cost != 0)
		{
			exec_rra(stack_a, 1);
			cost--;
		}
	}
}

void	sort_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost;

	if (get_stack_len(*stack_a) > 3)
		exec_pb(stack_a, stack_b, 1);
	if (get_stack_len(*stack_a) > 3 && !stack_sorted(*stack_a))
		exec_pb(stack_a, stack_b, 1);
	while (get_stack_len(*stack_a) > 3 && !stack_sorted(*stack_a))
	{
		tmp = *stack_a;
		cost = cheapest_move(*stack_a, *stack_b);
		while (cost >= 0)
		{
			if (cost == cost_ra_rb(*stack_a, *stack_b, tmp->index))
				cost = move_set_ra_rb(stack_a, stack_b, tmp->index);
			else if (cost == cost_rra_rrb(*stack_a, *stack_b, tmp->index))
				cost = move_set_rra_rrb(stack_a, stack_b, tmp->index);
			else if (cost == cost_ra_rrb(*stack_a, *stack_b, tmp->index))
				cost = move_set_ra_rrb(stack_a, stack_b, tmp->index);
			else if (cost == cost_rra_rb(*stack_a, *stack_b, tmp->index))
				cost = move_set_rra_rb(stack_a, stack_b, tmp->index);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		cost;

	while (*stack_b)
	{
		tmp_a = *stack_a;
		cost = 0;
		if (find_min_index(tmp_a) > (*stack_b)->index
			|| find_max_index(tmp_a) < (*stack_b)->index)
			cost = find_specific_index(tmp_a, find_min_index(tmp_a));
		else
		{
			while (tmp_a->next)
			{
				if ((*stack_b)->index > tmp_a->index
					&& (*stack_b)->index < tmp_a->next->index)
					cost = find_specific_index(*stack_a, tmp_a->index) + 1;
				tmp_a = tmp_a->next;
			}
		}
		if (cost > 0)
			exec_sort_a_moves(stack_a, cost);
		exec_pa(stack_a, stack_b, 1);
	}
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (get_stack_len(*stack_a) == 2)
		exec_sa(stack_a, 1);
	else
	{
		sort_b(stack_a, &stack_b);
		if (!stack_sorted(*stack_a))
			sort_only_three(stack_a);
		sort_a(stack_a, &stack_b);
		if (!stack_sorted(*stack_a))
			exec_sort_a_moves(stack_a,
				find_specific_index(*stack_a, find_min_index(*stack_a)));
	}
	stack_b = NULL;
}
