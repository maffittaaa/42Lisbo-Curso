/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:00:25 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/07 15:02:36 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Iterates the list ’lst’ and applies the function
//’f’ on the content of each node. Creates a new
//list resulting of the successive applications of
//the function ’f’. The ’del’ function is used to
//delete the content of a node if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*store;

	store = 0;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&store, del);
			return (NULL);
		}
		ft_lstadd_back(&store, new);
		lst = lst->next;
	}
	return (store);
}
