/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:33:29 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/03 18:20:53 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*area;

	area = (char *)malloc((count * size) * sizeof(*area));
	if (area == 0)
		return (0);
	ft_bzero(area, count * size);
	return (area);
}
/*
int	main()
{
	int	*calloc_test;
	calloc_test = (int *)ft_calloc(6, sizeof(int));
	printf("Calloc an array of 6 int\n    ");
	for(int i = 0; i < 6; i++)
		printf("%d ", calloc_test[i]);
	printf("\n");
	free(calloc_test);
}*/
