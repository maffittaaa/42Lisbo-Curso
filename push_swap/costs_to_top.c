/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:16:56 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:16:57 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	absolute(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void	calculate_moves(int *tmp_i, t_node **head_a, int *k, t_node *tmp_b)
{
	*k = get_best_friend(head_a, tmp_b->content);
	if (*k > length(head_a) / 2)
		*k = (length(head_a) - *k) * (-1);
	if (*tmp_i > length(&tmp_b) / 2)
		*tmp_i = (length(&tmp_b) - *tmp_i) * (-1);
}

void	find_best_move(t_node **head_a, t_node **head_b,
	int *moves_a, int *moves_b)
{
	t_node			*tmp_b;
	unsigned int	max_moves;
	int				i;
	int				k;
	int				tmp_i;

	max_moves = INT_MAX;
	i = 0;
	k = 0;
	tmp_b = *head_b;
	while (i < length(head_b))
	{
		tmp_i = i;
		calculate_moves(&tmp_i, head_a, &k, tmp_b);
		if ((absolute(tmp_i) + absolute(k)) < max_moves)
		{
			max_moves = absolute(tmp_i) + absolute(k);
			*moves_a = k;
			*moves_b = tmp_i;
		}
		i++;
		tmp_b = tmp_b->nextinline;
	}
	rest_of_cost_to_top(head_a, head_b, moves_a, moves_b);
}

void	rest_of_cost_to_top(t_node **head_a, t_node **head_b,
	int *moves_a, int *moves_b)
{
	while (*moves_b < 0)
	{
		reverse_rotate_b(head_b);
		(*moves_b) += 1;
	}
	while (*moves_b > 0)
	{
		rotate_b(head_b);
		(*moves_b) -= 1;
	}
	while (*moves_a > 0)
	{
		rotate_a(head_a);
		(*moves_a) -= 1;
	}
	while (*moves_a < 0)
	{
		reverse_rotate_a(head_a);
		(*moves_a) += 1;
	}
	push_a(head_b, head_a);
}
