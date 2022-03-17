/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:33:50 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/11 12:50:40 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_value_dst;
	char	*ds;
	char	*sr;

	original_value_dst = dst;
	ds = (char *)dst;
	sr = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		*ds = *sr;
		ds++;
		sr++;
	}
	return (original_value_dst);
}
/*
int		main(void)
{
	write(1, "ft_memcpy\n", 10);
	ft_memcpy(NULL, NULL, 0);
	write(1, "memcpy\n", 7);
	memcpy(NULL, NULL, 0);
}*/
