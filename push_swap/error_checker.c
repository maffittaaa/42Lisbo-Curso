/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:20:17 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:20:18 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_checker(int argc, char **argv, t_node **head_a)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (isnumber(argv[i]) == 0 && ft_printf("Error - Not a number\n"))
			return (1);
		if (ft_atol(argv[i]) > INT_MAX && ft_printf("Error - big number\n"))
			return (1);
		if (ft_atol(argv[i]) < INT_MIN && ft_printf("Error - small number\n"))
			return (1);
		i++;
	}
	i = 0;
	while (++i < argc)
		lstnew(head_a, ft_atoi(argv[i]));
	if (isduplicate(head_a) == 1 && ft_printf("Error - Duplicate numbers\n"))
		return (1);
	return (0);
}
