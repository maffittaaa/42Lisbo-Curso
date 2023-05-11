/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:17:53 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:55 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node **head_b)
{
	printf("sb\n");
	stack_swap(head_b);
}

void	rotate_b(t_node **head_b)
{
	printf("rb\n");
	stack_rotate(head_b);
}

void	reverse_rotate_b(t_node **head_b)
{
	printf("rrb\n");
	stack_reverse_rotate(head_b);
}

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	printf("pb\n");
	if (*head_a == NULL)
		return ;
	tmp = *head_a;
	if (length(head_a) > 1)
	{
		(*head_a)->previnline->nextinline = (*head_a)->nextinline;
		(*head_a)->nextinline->previnline = (*head_a)->previnline;
		*head_a = tmp->nextinline;
	}
	else
		*head_a = 0;
	complement_to_push_b(head_b, tmp);
}

void	complement_to_push_b(t_node **head_b, t_node *tmp)
{
	if (length(head_b) > 0)
	{
		tmp->nextinline = *head_b;
		tmp->previnline = (*head_b)->previnline;
		(*head_b)->previnline->nextinline = tmp;
		(*head_b)->previnline = tmp;
		*head_b = tmp;
	}
	else
	{
		*head_b = tmp;
		tmp->nextinline = tmp;
		tmp->previnline = tmp;
	}
}
