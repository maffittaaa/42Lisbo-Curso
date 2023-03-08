/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:11:46 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/07 15:03:02 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates (with malloc(3)) and returns a new node.
//The member variable ’content’ is initialized with
//the value of the parameter ’content’. The variable
//’next’ is initialized to NULL.
t_list	*ft_lstnew(void *content) 
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
