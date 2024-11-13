/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:55 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:48 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		cost;

	tmp = stack_a;
	cost = get_stack_len(stack_a) + get_stack_len(stack_b);
	while (tmp)
	{
		if (cost > cost_ra_rb(stack_a, stack_b, tmp->index))
			cost = cost_ra_rb(stack_a, stack_b, tmp->index);
		if (cost > cost_rra_rrb(stack_a, stack_b, tmp->index))
			cost = cost_rra_rrb(stack_a, stack_b, tmp->index);
		if (cost > cost_ra_rrb(stack_a, stack_b, tmp->index))
			cost = cost_ra_rrb(stack_a, stack_b, tmp->index);
		if (cost > cost_rra_rb(stack_a, stack_b, tmp->index))
			cost = cost_rra_rb(stack_a, stack_b, tmp->index);
		tmp = tmp->next;
	}
	return (cost);
}

int	cost_ra_rb(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	i = find_b_spot(stack_b, index);
	if (i < find_specific_index(stack_a, index))
		i = find_specific_index(stack_a, index);
	return (i);
}

int	cost_rra_rrb(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	i = 0;
	if (find_b_spot(stack_b, index))
		i = get_stack_len(stack_b) - find_b_spot(stack_b, index);
	if ((i < (get_stack_len(stack_a) - find_specific_index(stack_a, index)))
		&& find_specific_index(stack_a, index))
		i = get_stack_len(stack_a) - find_specific_index(stack_a, index);
	return (i);
}

int	cost_ra_rrb(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	i = 0;
	if (find_b_spot(stack_b, index))
		i = get_stack_len(stack_b) - find_b_spot(stack_b, index);
	i = find_specific_index(stack_a, index) + i;
	return (i);
}

int	cost_rra_rb(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	i = 0;
	if (find_specific_index(stack_a, index))
		i = get_stack_len(stack_a) - find_specific_index(stack_a, index);
	i = find_b_spot(stack_b, index) + i;
	return (i);
}
