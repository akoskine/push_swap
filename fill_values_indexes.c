/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values_indexes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:43 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:55 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_new(int value)
{
	t_stack	*res;

	res = malloc(sizeof * res);
	if (!res)
		return (NULL);
	res->value = value;
	res->index = 0;
	res->next = NULL;
	return (res);
}

void	fill_values(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	fill_index(t_stack *stack, int stack_len)
{
	t_stack	*tmp_stack;
	t_stack	*biggest;
	int		tmp_value;

	while (--stack_len > 0)
	{
		tmp_stack = stack;
		biggest = NULL;
		tmp_value = INT_MIN;
		while (tmp_stack)
		{
			if (tmp_stack->value == INT_MIN && !tmp_stack->index)
				tmp_stack->index = 1;
			if (tmp_stack->value > tmp_value && !tmp_stack->index)
			{
				tmp_value = tmp_stack->value;
				biggest = tmp_stack;
				tmp_stack = stack;
			}
			else
				tmp_stack = tmp_stack->next;
		}
		if (biggest != NULL)
			biggest->index = stack_len;
	}
}

t_stack	*quoted_str(char **argv)
{
	t_stack		*stack_a;
	long int	value;
	int			i;
	char		**tmp;

	stack_a = NULL;
	value = 0;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		value = ft_atoi_long(tmp[i]);
		if (value < INT_MIN || value > INT_MAX)
			exit_error(&stack_a, NULL);
		fill_values(&stack_a, fill_new(value));
		i++;
	}
	ft_free_str (tmp);
	free (tmp);
	fill_index (stack_a, get_stack_len(stack_a) + 1);
	return (stack_a);
}

t_stack	*fill_values_indexes(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	value;
	int			i;

	stack_a = NULL;
	value = 0;
	i = 1;
	if (argc == 2)
		stack_a = quoted_str(argv);
	else
	{
		while (i < argc)
		{
			value = ft_atoi_long (argv[i]);
			if (value < INT_MIN || value > INT_MAX)
				exit_error (&stack_a, NULL);
			fill_values (&stack_a, fill_new(value));
			i++;
		}
		fill_index (stack_a, get_stack_len(stack_a) + 1);
	}
	return (stack_a);
}
