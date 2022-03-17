/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:53:10 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/02 12:52:24 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static char	*output(char *string, int neg, int index)
{
	int		size;
	char	*out;
	int		j;

	size = 11 - index + neg - 1;
	out = (char *)malloc((size + 1) * sizeof(*out));
	if (!out)
		return (NULL);
	out[size] = '\0';
	size--;
	j = 10;
	while (size >= 0)
	{
		out[size] = string[j];
		size--;
		j--;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	char	string[11];
	int		d;
	int		neg;
	long	l;

	d = 10;
	l = (long)n;
	neg = 0;
	if (l == 0)
		return (output("01234567890", 0, 9));
	if (l < 0)
	{
		neg = 1;
		l = -l;
	}
	while (l != 0)
	{
		string[d] = "0123456789"[l % 10];
		l = l / 10;
		d--;
	}
	if (neg == 1)
		string[d] = '-';
	return (output(string, neg, d));
}
/*
int main()
{
	printf("48 to string : %s\n", ft_itoa(48));
	printf("0 to string : %s\n", ft_itoa(0) );
	printf("-6115048 to string : %s\n", ft_itoa(-6115048) );
	printf("2147483647 to string : %s\n", ft_itoa(2147483647) );
	printf("-2147483648 to string : %s\n", ft_itoa(-2147483648));
}*/
