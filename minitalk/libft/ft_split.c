/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:55:17 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/17 17:29:17 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_counter(char const *s, char c)
{
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**destiny;
	char	*source;
	size_t	i;

	destiny = (char **)malloc(sizeof(char *) * char_counter(s, c) + 1);
	if (!s || !destiny)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			source = (char *)s;
			while (*s && *s != c)
				s++;
			destiny[i] = (char *)malloc(s - source + 1);
			if (!destiny)
				return (0);
			ft_strlcpy(destiny[i++], source, s - source + 1);
		}
		else
			s++;
	}
	destiny[i] = 0;
	return (destiny);
}
