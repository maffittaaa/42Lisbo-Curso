/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:18:49 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/07 15:02:11 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// retorna o ultimo node da lista
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = 0;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
