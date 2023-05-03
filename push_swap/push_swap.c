/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:18:36 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:18:38 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	if (error_checker(argc, argv, &head_a))
	{
		lstiter_node(&head_a, free);
		return (1);
	}
	if (length(&head_a) > 9)
		ten_or_more(&head_a, &head_b);
	else if (length(&head_a) == 3)
		three_numbers(&head_a);
	else
		five_numbers(&head_a, &head_b, length(&head_a));
	lstiter_node(&head_a, free);
	return (0);
}
