/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:02:13 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:45 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}

char	*check_stack(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		exec_sa(stack_a, 0);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		exec_pa(stack_a, stack_b, 0);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		exec_ra(stack_a, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		exec_rra(stack_a, 0);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		exec_sb(stack_b, 0);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		exec_pb(stack_a, stack_b, 0);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		exec_rb(stack_b, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		exec_rrb(stack_b, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		exec_rrr(stack_a, stack_b, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		exec_rr(stack_a, stack_b, 0);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		exec_ss(stack_a, stack_b, 0);
	else
		checker_exit_error(stack_a, stack_b);
	return (get_next_line(0));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (!check_input(argc, argv))
		exit_error(NULL, NULL);
	stack_a = fill_values_indexes (argc, argv);
	str = get_next_line(0);
	while (str && *str != '\n')
		str = check_stack(&stack_a, &stack_b, str);
	if (stack_b || !stack_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free (str);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}
