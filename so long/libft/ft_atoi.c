/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:17 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/02 12:52:55 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int					neg;
	unsigned long int	result;
	size_t				index;

	neg = 1;
	result = 0;
	index = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			neg *= -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + (str[index] - 48);
		index++;
	}
	return (result * neg);
}
/*
int main()
{
	char e[] = {9, 10, 11, 12, 13, 0};

	if (ft_atoi((e + "--1")))
		printf("WHAT\n");
	if (ft_atoi((e + "++1")))
		printf("THE\n");
	if (ft_atoi("-+42") == 0)
		printf("FREAKING\n");
	if (ft_atoi("+-42") == 0)
		printf("FUCK\n");
}*/
