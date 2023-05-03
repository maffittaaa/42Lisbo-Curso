/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:19:34 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:19:36 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstiter(t_node **head, void (*f)(int *))
{
	t_node	*temp;
	t_node	*next;

	if (!*head)
		return ;
	next = (*head)->nextinline;
	f(&(*head)->content);
	temp = next;
	while (temp != *head)
	{
		next = temp->nextinline;
		f(&temp->content);
		temp = next;
	}
}

//dar free aos nodes todos
void	lstiter_node(t_node **head, void (*k)(void *))
{
	t_node	*temp;
	t_node	*next;

	if (!*head)
		return ;
	next = (*head)->nextinline;
	k((*head));
	temp = next;
	while (temp != *head)
	{
		next = temp->nextinline;
		k(temp);
		temp = next;
	}
}
