/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:27:52 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 12:53:58 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*i;

	i = (char *)b;
	while (len > 0)
	{
		i[len - 1] = c;
		len--;
	}
	return (b);
}
