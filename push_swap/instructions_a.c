/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:16:02 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:16:06 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **head_a)
{
	printf("sa\n");
	stack_swap(head_a);
}

void	rotate_a(t_node **head_a)
{
	printf("ra\n");
	stack_rotate(head_a);
}

void	reverse_rotate_a(t_node **head_a)
{
	printf("rra\n");
	stack_reverse_rotate(head_a);
}

void	push_a(t_node **head_b, t_node **head_a)
{
	t_node	*tmp;

	printf("pa\n");
	if (*head_b == NULL)
		return ;
	tmp = *head_b;
	if (length(head_b) > 1)
	{
		(*head_b)->previnline->nextinline = (*head_b)->nextinline;
		(*head_b)->nextinline->previnline = (*head_b)->previnline;
		*head_b = tmp->nextinline;
	}
	else
		*head_b = 0;
	complement_to_push_a(head_b, head_a);
}

void	complement_to_push_a(t_node **head_b, t_node **head_a)
{
	t_node	*tmp;

	tmp = *head_b;
	if (length(head_a) > 0)
	{
		tmp->nextinline = *head_a;
		tmp->previnline = (*head_a)->previnline;
		(*head_a)->previnline->nextinline = tmp;
		(*head_a)->previnline = tmp;
		*head_a = tmp;
	}
	else
	{
		*head_a = tmp;
		tmp->nextinline = tmp;
		tmp->previnline = tmp;
	}
}
