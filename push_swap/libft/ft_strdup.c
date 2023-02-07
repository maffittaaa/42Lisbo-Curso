/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:31:40 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/17 17:29:26 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*duplicate;
	int		index;

	size = 0;
	while (src[size] != '\0')
		size++;
	duplicate = malloc(size + 1);
	if (duplicate == 0)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		duplicate[index] = src[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
