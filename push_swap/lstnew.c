/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:16:17 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:16:19 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstnew(t_node **head, int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = number;
	if (!*head)
	{
		(*head) = new_node;
		new_node->previnline = new_node;
		new_node->nextinline = new_node;
	}
	else
	{
		new_node->previnline = (*head)->previnline;
		(*head)->previnline->nextinline = new_node;
		(*head)->previnline = new_node;
		new_node->nextinline = *head;
	}
}
