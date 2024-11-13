/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:57 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:09 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int		tmp;

	tmp = stack->index;
	while (stack)
	{
		if (stack->index > tmp)
			tmp = stack->index;
		stack = stack->next;
	}
	return (tmp);
}

int	find_min_index(t_stack *stack)
{
	int		tmp;

	tmp = stack->index;
	while (stack)
	{
		if (stack->index < tmp)
			tmp = stack->index;
		stack = stack->next;
	}
	return (tmp);
}

int	find_specific_index(t_stack *stack, int index)
{
	int		i;

	i = 0;
	while (stack->index != index)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_last_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int	find_b_spot(t_stack *stack_b, int index)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (index > stack_b->index && index < find_last_index(stack_b))
		i = 0;
	else if (index < find_min_index(stack_b) || index > find_max_index(stack_b))
		i = find_specific_index(stack_b, find_max_index(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->index < index || tmp->index > index)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}
