/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:07:03 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 13:59:01 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	i;

	a = 0;
	while (src[a] != '\0')
		a++;
	i = 0;
	if (size < 1)
		return (a);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}
/*
int main()
{
    char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);

	if (ft_strlcpy(dest, src, 0) == strlen(src))
		printf("STRLEN certo \n");
	if (dest[0] == 'A')
		printf("dest[0] = A\n");
}*/
