/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:10:51 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 16:21:39 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
/*
int main(void)
{
	char s[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};

	if (ft_memcmp(s, s2, 1) > 0)
		printf("RESULTADO");
	if (ft_memcmp(s2, s, 1) < 0)
		printf("RESULTADO");

}*/
