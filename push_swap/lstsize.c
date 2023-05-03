/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:18:15 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:18:17 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_node **head)
{
	t_node	*temp;
	int		size;

	if (!*head)
		return (0);
	temp = (*head)->nextinline;
	size = 1;
	while (temp != *head)
	{
		size++;
		temp = temp->nextinline;
	}
	return (size);
}
