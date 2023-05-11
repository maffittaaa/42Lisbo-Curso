/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:15:55 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/09 19:15:57 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->nextinline != *head)
	{
		if (tmp->content > tmp->nextinline->content)
			return (0);
		tmp = tmp->nextinline;
	}
	return (1);
}
