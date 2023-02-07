/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:28:04 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/11 12:26:57 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = 0;
	if (!*lst)
		*lst = new;
	else
	{	
		while (*lst != NULL)
		{
			last = *lst;
			lst = &((*lst)->next);
		}
		last->next = new;
	}
}
