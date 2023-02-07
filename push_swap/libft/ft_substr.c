/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:45:15 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/24 18:39:31 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	e;

	i = 0;
	e = 0;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && e < len)
		{
			substr[e] = s[i];
			e++;
		}
		i++;
	}
	substr[e] = '\0';
	return (substr);
}
/*
int main()
{
	char* str;

	str = ft_substr("Hello, 42Seoul!", 7, 2);
	printf("%s\n", str);

	return 0;
}*/
