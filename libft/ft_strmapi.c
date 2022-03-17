/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:16:39 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/01 12:34:58 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	new = ft_strdup((char *)s);
	if (!new)
		return (NULL);
	i = 0;
	while (new[i] != '\0')
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
