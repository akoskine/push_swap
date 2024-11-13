/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:20 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:42 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nbr(char *arg, int *zero)
{
	int	z;

	z = 1;
	if ((*arg == '-' || *arg == '+') && *(arg + 1) != '\0')
		arg++;
	while (*arg >= '0' && *arg <= '9')
	{
		if (*arg != '0')
			z = 0;
		arg++;
	}
	if (z)
		*zero = *zero + 1;
	if (*arg == '\0')
		return (1);
	else
		return (0);
}

int	check_duplicates(char **arg, int start)
{
	int	i;
	int	j;

	i = start;
	while (arg[i])
	{
		j = start;
		while (arg[j])
		{
			if (j != i && ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	quoted_arg(char **argv)
{
	char		**tmp;
	int			i;
	int			check;
	static int	zero;

	i = 0;
	check = 1;
	zero = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		if (!check_nbr(tmp[i], &zero) || zero > 1)
			check = 0;
		i++;
	}
	if (check_duplicates(tmp, 0))
		check = 0;
	ft_free_str(tmp);
	free(tmp);
	if (check == 0)
		return (0);
	else
		return (1);
}

int	check_input(int argc, char **argv)
{
	int			i;
	static int	zero;

	i = 1;
	zero = 0;
	if (argc == 2)
	{
		if (!quoted_arg(argv))
			return (0);
		return (1);
	}
	else
	{
		while (argv[i])
		{
			if (!check_nbr(argv[i], &zero) || zero > 1 || argv[i][0] == '\0')
				return (0);
			i++;
		}
		if (check_duplicates(argv, 1))
			return (0);
		return (1);
	}
}
