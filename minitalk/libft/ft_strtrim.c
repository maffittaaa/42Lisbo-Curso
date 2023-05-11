/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:11:19 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/02 13:02:10 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	check_set(char const *set, char const c)
{
	while (c != *set && *set)
		set++;
	return (*set != '\0');
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	while (check_set(set, s1[i]))
		i++;
	size_s1 = ft_strlen(s1) - 1;
	while (size_s1 >= i && check_set(set, s1[size_s1]))
		size_s1--;
	return (ft_substr(s1, i, size_s1 + 1 - i));
}
