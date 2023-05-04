/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:39:06 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 19:39:08 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_three_sorted(t_node **head)
{
	return ((*head)->content < (*head)->nextinline->content
		&& (*head)->content < (*head)->previnline->content
		&& (*head)->nextinline->content < (*head)->previnline->content);
}

void	three_numbers(t_node **head)
{
	if (length(head) <= 1)
		return ;
	if (is_three_sorted(head))
		return ;
	else if ((*head)->content < (*head)->previnline->content
		&& (*head)->content < (*head)->nextinline->content)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if ((*head)->content < (*head)->previnline->content
		&& (*head)->content > (*head)->nextinline->content)
		swap_a(head);
	else if ((*head)->content > (*head)->previnline->content
		&& (*head)->content < (*head)->nextinline->content)
		reverse_rotate_a(head);
	else if ((*head)->nextinline->content > (*head)->previnline->content
		&& (*head)->nextinline->content < (*head)->content)
	{
		swap_a(head);
		reverse_rotate_a(head);
	}
	else if ((*head)->nextinline->content < (*head)->previnline->content
		&& (*head)->nextinline->content < (*head)->content)
		rotate_a(head);
}
