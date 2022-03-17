/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:18:37 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/18 19:12:17 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*need;
	char	*hay;
	int		i;
	int		l;

	need = (char *)needle;
	hay = (char *)haystack;
	i = 0;
	while (need[i] == '\0')
		return (hay);
	while (hay[i] != '\0' && (unsigned int)i < len)
	{
		l = 0;
		while (need[l] != '\0' && hay[i + l] == need[l]
			&& (unsigned int)(i + l) < len && hay[i + l] != '\0')
		{
			if (need[l + 1] == '\0')
				return (&hay[i]);
			l++;
		}
		i++;
	}
	return (0);
}
/*
int   main()
{
    char str[] = "abcDEFghijklmDEFnopqrstuvwxyz";
    char fnd[] = "DEF";
    printf("%s", ft_strnstr(str, fnd, 7));
    return (0);
}*/
