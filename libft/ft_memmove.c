/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:26:38 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/02 12:58:40 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	if (dst == NULL && src == NULL)
		return (0);
	i = (int)len;
	if (src < dst)
		while (--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	else
	{
		i = 0;
		while (i < (int)len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main()
{
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	ft_memmove(sResult, sResult2, 5);
	if (ft_memmove(sResult + 1, sResult, 2) == sResult + 1)
		printf("RESULT1");
	if (!(ft_memcmp(sResult, sResult2, 7)))
		printf("RESULT3");

}*/
