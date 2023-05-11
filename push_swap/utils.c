/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:17:34 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:36 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int					neg;
	unsigned long		result;
	size_t				index;

	neg = 1;
	result = 0;
	index = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			neg *= -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + (str[index] - 48);
		index++;
	}
	return (result * neg);
}

int	length(t_node **head)
{
	int		i;
	t_node	*temp;

	i = 1;
	if (*head == NULL)
		return (0);
	temp = *head;
	while (temp->nextinline != *head)
	{
		temp = temp->nextinline;
		i++;
	}
	return (i);
}

void	min_up(t_node **head_a)
{
	t_node	*tmp;
	int		min;
	int		i;

	min = find_min(head_a);
	i = 0;
	tmp = *head_a;
	while (tmp->content != min)
	{
		i++;
		tmp = tmp->nextinline;
	}
	if (i > length(head_a) / 2)
		i = (length(head_a) - i) * (-1);
	while (i < 0)
	{
		reverse_rotate_a(head_a);
		i++;
	}
	while (i > 0)
	{
		rotate_a(head_a);
		i--;
	}
}
