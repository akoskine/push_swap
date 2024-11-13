/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:39 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:23:16 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	get_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (i > stack->index)
			return (0);
		i = stack->index;
		stack = stack->next;
	}
	return (1);
}

long int	ft_atoi_long(const char *str)
{
	long int	a;
	int			b;

	a = 0;
	b = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		b *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	return (a * b);
}
