/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:16:39 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:16:43 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verificar se o argumento que esta a ser passado e um numero
//verificar cada caracter do argumento
int	isnumber(char *number)
{
	int	i;

	i = 0;
	if (ft_strlen(number) > 11)
		return (0);
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] != 0)
	{
		if (ft_isdigit(number[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

//verificar se o argumento passado e duplicado
int	isduplicate(t_node **head)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*head == NULL)
		return (0);
	tmp = *head;
	while (tmp->nextinline != *head)
	{
		tmp2 = tmp->nextinline;
		while (tmp2->nextinline != (*head)->nextinline)
		{
			if (tmp->content == tmp2->content)
				return (1);
			tmp2 = tmp2->nextinline;
		}
		tmp = tmp->nextinline;
	}
	return (0);
}

int	find_max(t_node **head)
{
	t_node	*max;
	t_node	*temp;

	temp = (*head)->nextinline;
	max = *head;
	while (temp != *head)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->nextinline;
	}
	return (max->content);
}

int	find_min(t_node **head)
{
	t_node	*min;
	t_node	*temp;

	temp = (*head)->nextinline;
	min = *head;
	while (temp != *head)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->nextinline;
	}
	return (min->content);
}

void	print_integer(int *content)
{
	printf("%d\n", *content);
}
