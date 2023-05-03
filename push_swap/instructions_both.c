/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:20:36 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:20:38 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_swaps(t_node **head)
{
	printf("ss\n");
	stack_swap(head);
}

void	both_rotates(t_node **head)
{
	printf("rr\n");
	stack_rotate(head);
}

void	both_reverse_rotates(t_node **head)
{
	printf("rrr\n");
	stack_reverse_rotate(head);
}
