/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:47:57 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/21 17:36:56 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;
	char			*str;

	str = (char *)s;
	len = ft_strlen(str);
	if ((char) c == '\0')
		return (str + len);
	while (len--)
	{
		if (str[len] == (char) c)
			return (str + len);
	}
	return (NULL);
}
/*
int main()
{
	char s[] = "tripouille";

	if (ft_strrchr(s, 't' + 256) == s)
		printf("FUCK");
}*/
