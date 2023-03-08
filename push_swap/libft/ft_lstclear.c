/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:27:43 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/07 15:01:54 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Deletes and frees the given node and every
//successor of that node, using the function ’del’
//and free(3).
//Finally, the pointer to the list must be set to
//NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = next;
	}
}
