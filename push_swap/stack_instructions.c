/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:19:57 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:19:59 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_node **head)
{
	t_node	*thead;
	t_node	*sec;

	if (length(head) <= 1)
		return ;
	thead = (*head);
	sec = (*head)->nextinline;
	thead->previnline->nextinline = sec;
	sec->nextinline->previnline = thead;
	thead->nextinline = sec->nextinline;
	sec->nextinline = thead;
	sec->previnline = thead->previnline;
	thead->previnline = sec;
	(*head) = sec;
}

void	stack_rotate(t_node **head)
{
	*head = (*head)->nextinline;
}

void	stack_reverse_rotate(t_node **head)
{
	*head = (*head)->previnline;
}
