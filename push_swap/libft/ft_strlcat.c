/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:06:22 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/02/18 19:07:38 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	source_size;
	unsigned int	destiny_size;
	unsigned int	resultado;

	destiny_size = 0;
	while (dest[destiny_size] != '\0')
		destiny_size++;
	source_size = 0;
	while (src[source_size] != '\0')
		source_size++;
	resultado = source_size;
	if (size <= destiny_size)
		resultado = resultado + size;
	else
		resultado = resultado + destiny_size;
	source_size = 0;
	while (src[source_size] != '\0' && destiny_size + 1 < size)
	{
		dest[destiny_size] = src[source_size];
		destiny_size++;
		source_size++;
	}
	dest[destiny_size] = '\0';
	return (resultado);
}
