/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:46:09 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 17:32:51 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{	
	char	*st;

	st = (char *)s;
	while (*st != '\0')
	{
		if (*st == (char) c)
			return (st);
		st++;
	}
	if ((char) c == *st)
		return (st);
	return (NULL);
}
/*
int main()
{
	char s[] = "tripouille";

	if (ft_strchr(s, 'z') == 0)
		printf("Result:");
}*/
