/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:55:40 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 16:15:12 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned int	i;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*src == (unsigned char) c)
			return ((void *)src);
		src++;
		i++;
	}
	src = 0;
	return ((void *)src);
}
/*
int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	if (ft_memchr(s, 2 + 256, 3) == s + 2)
		printf("RESULTADO:");
}*/
