/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:03 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:57 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (!check_input(argc, argv))
		exit_error(NULL, NULL);
	stack_a = fill_values_indexes (argc, argv);
	if (!stack_sorted(stack_a))
		sort (&stack_a);
	free_stack (&stack_a);
	return (0);
}
