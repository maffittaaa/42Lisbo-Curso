/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_to_nine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:40:36 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 19:40:38 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers(t_node **head_a, t_node **head_b, int len)
{
	int	max;
	int	min;

	max = find_max(head_a);
	min = find_min(head_a);
	while (length(head_a) > 3)
		push_b(head_a, head_b);
	three_numbers(head_a);
	while (length(head_a) < len)
	{
		if ((*head_b)->content == max
			|| (*head_b)->content == min
			|| (*head_b)->content > find_max(head_a)
			|| (*head_b)->content < find_min(head_a))
			while ((*head_a)->content != find_min(head_a))
				rotate_a(head_a);
		else
			while (!((*head_a)->content > (*head_b)->content
					&& (*head_a)->previnline->content < (*head_b)->content))
				rotate_a(head_a);
		push_a(head_b, head_a);
	}
	min_up(head_a);
}
