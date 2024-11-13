/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:07:45 by akoskine          #+#    #+#             */
/*   Updated: 2022/12/08 18:54:51 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	n = n - 1;
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n != 0)
	{
	s1++;
	s2++;
	n--;
	}
	if ((unsigned char )*s1 > (unsigned char )*s2)
		return (1);
	else if ((unsigned char )*s1 < (unsigned char )*s2)
		return (-1);
	return (0);
}